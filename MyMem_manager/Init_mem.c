#include <stdio.h>
#include "def.h"

extern int start;
extern char mem_buf[];

void Init_Mem()
{
	start = 0;
	*(int *)(mem_buf + start) = (int)(TOTAL_MEM_SIZE - HEAD_SIZE);

	*(int *)(mem_buf + start + NEXT_INDEX) = WAS_END;

}
