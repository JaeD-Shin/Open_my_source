#include <stdio.h>
#include "def.h"

extern int start;
extern char mem_buf[];
extern void view_mem_stat(char *msg);

void myfree(int addr)
{
	int st = start;
	int free_pos = addr;
	int free_size = *(int *)(mem_buf + free_pos);

	int preLink = -1;
	int my_size;
	int free_flag = 0;

	int idx = 0;


	while (st >= 0) {
		my_size = *(int *)(mem_buf + st);

		if (free_pos > st && free_pos < (st + my_size + HEAD_SIZE)) {
			printf("FREE AREA ERROR\n");
			return;
		}


		if ((st + my_size + HEAD_SIZE) == free_pos) {  // st + free_pos

			*(int *)(mem_buf + st) += (free_size + HEAD_SIZE);  
			free_pos = st;   
			free_size = *(int *)(mem_buf + st); 

			if (preLink < 0) {  
				start = *(int *)(mem_buf + st + NEXT_INDEX);
				st = start;
				if (free_flag == 0) {
					free_flag = 1; 
					continue;  
				}
			}
			else {
				*(int *)(mem_buf + preLink + NEXT_INDEX) = *(int *)(mem_buf + st + NEXT_INDEX);
			}

			if (free_flag != 0)   
				break;
			free_flag = 1;	
		}

		if ((free_pos + free_size + HEAD_SIZE) == st) { 

			*(int *)(mem_buf + free_pos) += (*(int *)(mem_buf + st) + HEAD_SIZE);
			free_size = *(int *)(mem_buf + free_pos);


			if (preLink < 0) { 
				start = *(int *)(mem_buf + st + NEXT_INDEX);
				st = start;
				if (free_flag == 0) {
					free_flag = 1; 
					continue;  
				}
			}
			else {
				*(int *)(mem_buf + preLink + NEXT_INDEX) = *(int *)(mem_buf + st + NEXT_INDEX);
				st = preLink;
			}


			if (free_flag != 0)   // 2번째 합병 이어서 while loop를 탈출
				break;

			free_flag = 1;	// 첫번째 합병이 완료 되었음
		}

		preLink = st;
		st = *(int *)(mem_buf + st + NEXT_INDEX);
	}

	*(int *)(mem_buf + free_pos + NEXT_INDEX) = start;
	start = free_pos;
}


void MyFree(void *addr)
{
	int free_pos = (int)addr - (int)mem_buf - HEAD_SIZE;

	if (addr == NULL)
		return;

	myfree(free_pos);
}

