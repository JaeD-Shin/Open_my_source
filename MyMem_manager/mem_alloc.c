#include <stdio.h>
#include "def.h"
#include <time.h>

extern int start;
extern char mem_buf[];
extern int fit_option;


int myalloc(int size)
{
	clock_t time_start, time_end;
	double result;

	time_start = clock();

	int st = start;
	int pre = -1;
	int next = -1;
	int new_st = -1;
	
	int pre_fit= -1;
	int fit_st = -1;
	int fit_size = TOTAL_MEM_SIZE;

	int free = FALSE;
	int pos = FALSE_POS;
	int empty_size = 0;
	int my_size = 0;
	int next_value = -1;

	if (fit_option == FIRST_FIT) { // FIRST-FIT
		while (TRUE) {
			my_size = *(int *)(mem_buf + st);
			next_value = *(int *)(mem_buf + st + NEXT_INDEX);


			
			empty_size = my_size - size;
			//printf("EMPTY_SIZE=%d %d\n",empty_size, *(int *)(mem_buf + st));
			if (empty_size >= 0) {
				break;
			}

			if (next_value == WAS_END) {
				return FALSE_POS;
			}

			pre = st;
			st = next_value;
		}
	}
	else {  // BESST-FIT

		while (TRUE) {
			my_size = *(int *)(mem_buf + st);
			next_value = *(int *)(mem_buf + st + NEXT_INDEX);
			if (my_size == size) {
				pre_fit = pre;
				fit_st = st;
				printf("BEST FIT : Same\n");
				break;
			}

			if (my_size > size) {
				if (fit_size > my_size) {
					fit_size = my_size;
					pre_fit = pre;
					fit_st = st;
				}
			}

			if (next_value == WAS_END) {
				break;
			}

			pre = st;
			st = next_value;
		}

		if (fit_st == WAS_END) {
			return FALSE_POS;
		}


		st = fit_st;
		pre = pre_fit;
		empty_size = my_size - size;


	}

	if (empty_size >= HEAD_SIZE) {
		printf("���� �޸𸮰� HEAD ũ�⺸�� ũ�ų� ���� ����� ó��\n");
		new_st = st + size + HEAD_SIZE;
		if (pre != -1) {
			*(int *)(mem_buf + pre + NEXT_INDEX) = new_st;
		}
		else { 
			start = new_st;
		}

		*(int *)(mem_buf + new_st) = my_size - (size + HEAD_SIZE);
		*(int *)(mem_buf + new_st + NEXT_INDEX) = *(int *)(mem_buf + st + NEXT_INDEX);
		*(int *)(mem_buf + st) = size;
	}
	else {
		printf("���� �޸𸮰� HEAD ũ�⺸�� ���� ����� ó��\n");
		if (pre != -1) {
			*(int *)(mem_buf + pre + NEXT_INDEX) = next_value;
		}
		else { // st ��  head_ptr ��
			if (next_value == WAS_END) {
				start = -1;
			}
			else {
				start = next_value;
			}
		}

	}

	*(int *)(mem_buf + st + NEXT_INDEX) = WAS_ALLOC;

	time_end = clock(); //�ð� ���� �� 
	result = (double)(time_end - time_start);
	printf("�ð� ���� : %f\n", result);

	return st; // ������� POS return
	
}

void *MyMalloc(int size)
{
	int pos;

	if (start < 0) {
		printf("Memory was full allocated\n");
		return NULL;
	}

	pos = myalloc(size);
	if (pos == FALSE_POS) {
		printf("Memory is insufficient !!!\n");
		return NULL;
	}

	//return (void *)&mem_buf[pos + sizeof(HEAD)];
	printf("\n�䱸�� �޸� %d ����Ʈ�� ���������Ҵ���\n", size);
	return (void *)(mem_buf + pos + HEAD_SIZE);
}

