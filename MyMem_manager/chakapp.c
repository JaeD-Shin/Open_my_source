#include "def.h"
#include <stdlib.h>
extern int start;
extern char mem_buf[];

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int *)a; 
	int num2 = *(int *)b; 

	if (num1 < num2) 
		return -1;   

	if (num1 > num2)  
		return 1;       

	return 0;    
}

void prtf_alloc_area(int s_addr, int e_addr)
{

	int size;
	int next;

	while (s_addr < e_addr) {
		size = *(int *)(mem_buf + s_addr); 
		next = *(int *)(mem_buf + s_addr + NEXT_INDEX); 

		printf("+--------+------+-----------+\n");
		printf("| ALLOC  | %4d | %4d/%-4d |\n", s_addr, size, next);

		s_addr += (size + HEAD_SIZE); 
	}

}


void view_mem_stat(char *msg)
{
	int st = start;
	int count = 0;
	int *mem_addr, *ptr, *pre = NULL;
	int my_size, my_next, size;
	int nStart = 0;  // 할당된 공간의 시작 주소를 설정하기 위한 변수
	int i;


	printf("<<<<<< After %s >>>>> \n", msg);
	printf("+--------+------+-----------+\n");
	printf("|        | ADDR | Size/Next |\n");
	st = start;
	// 메모리 내부에 있는 빈공간의 개수를 확인한다. 
	while (st >= 0) {
		st = *(int *)(mem_buf + st + NEXT_INDEX);
		count++;
	}

	if (count == 0) {
		prtf_alloc_area(nStart, TOTAL_MEM_SIZE);
		printf("+--------+------+-----------+\n");
		return;
	}

	mem_addr = (int *)malloc(sizeof(int) * count);
	ptr = mem_addr;
	st = start;

	while (st >= 0) {
		*ptr = st;
		st = *(int *)(mem_buf + st + NEXT_INDEX);
		ptr++;
	}

	ptr = mem_addr;

	// 빈공간 주소가 저장된 영역을 주소순서로 sorting 한다.
	if (count > 1)
		qsort(ptr, count, sizeof(int), compare);



	for (i = 0; i < count; i++) {
		my_size = *(int *)(mem_buf + *ptr);
		my_next = *(int *)(mem_buf + *ptr + NEXT_INDEX);

		// 할당된 영역을 분리하여 출력
		prtf_alloc_area(nStart, *ptr);

		// 빈공간 출력함
		printf("+--------+------+-----------+\n");
		printf("| %s | %4d | %4d/%-4d |\n", (start == *ptr) ? "HEADER" : "      ", *ptr, my_size, my_next);

		nStart = *ptr + my_size + HEAD_SIZE;  // 할당된 주소의 처음 주소를 설정

		ptr++;
	}

	// 마지막 빈공간 뒤에 할당된 영역을 출력
	prtf_alloc_area(nStart, TOTAL_MEM_SIZE);
	printf("+--------+------+-----------+\n");

	free(mem_addr);
}
