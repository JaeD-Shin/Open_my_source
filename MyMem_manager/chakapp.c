#include "def.h"
#include <stdlib.h>
extern int start;
extern char mem_buf[];

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
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
	int nStart = 0;  // �Ҵ�� ������ ���� �ּҸ� �����ϱ� ���� ����
	int i;


	printf("<<<<<< After %s >>>>> \n", msg);
	printf("+--------+------+-----------+\n");
	printf("|        | ADDR | Size/Next |\n");
	st = start;
	// �޸� ���ο� �ִ� ������� ������ Ȯ���Ѵ�. 
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

	// ����� �ּҰ� ����� ������ �ּҼ����� sorting �Ѵ�.
	if (count > 1)
		qsort(ptr, count, sizeof(int), compare);



	for (i = 0; i < count; i++) {
		my_size = *(int *)(mem_buf + *ptr);
		my_next = *(int *)(mem_buf + *ptr + NEXT_INDEX);

		// �Ҵ�� ������ �и��Ͽ� ���
		prtf_alloc_area(nStart, *ptr);

		// ����� �����
		printf("+--------+------+-----------+\n");
		printf("| %s | %4d | %4d/%-4d |\n", (start == *ptr) ? "HEADER" : "      ", *ptr, my_size, my_next);

		nStart = *ptr + my_size + HEAD_SIZE;  // �Ҵ�� �ּ��� ó�� �ּҸ� ����

		ptr++;
	}

	// ������ ����� �ڿ� �Ҵ�� ������ ���
	prtf_alloc_area(nStart, TOTAL_MEM_SIZE);
	printf("+--------+------+-----------+\n");

	free(mem_addr);
}
