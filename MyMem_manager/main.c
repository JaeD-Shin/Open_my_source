#include <stdio.h>

extern void view_mem_stat(char *msg);
extern void *MyMalloc(int size);
extern void MyFree(void *addr);
extern void Init_Mem();

int main()
{

	int a, b, c, d,e,f,g,i,j,k;
	char msg[128];

	sprintf(msg, "Init memory");
	printf("CAll ===>  %s\n", msg);
	Init_Mem();

	view_mem_stat(msg);

	
	sprintf(msg, "A Alloc 5");
	printf("CAll ===>  %s\n", msg);
	a = (int)MyMalloc(5);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "B  Alloc 6");
	printf("CAll ===>  %s\n", msg);
	b = (int)MyMalloc(6);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "C  Alloc 10");
	printf("CAll ===>  %s\n", msg);
	c = (int)MyMalloc(10);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "D  Alloc 17");
	printf("CAll ===>  %s\n", msg);
	d = (int)MyMalloc(17);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "E  Alloc 10");
	printf("CAll ===>  %s\n", msg);
	e = (int)MyMalloc(10);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "F  Alloc 18");
	printf("CAll ===>  %s\n", msg);
	f = (int)MyMalloc(18);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "G  Alloc 8");
	printf("CAll ===>  %s\n", msg);
	g = (int)MyMalloc(8);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "I  Alloc 25");
	printf("CAll ===>  %s\n", msg);
	i = (int)MyMalloc(25);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "J  Alloc 20");
	printf("CAll ===>  %s\n", msg);
	j = (int)MyMalloc(20);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "K  Alloc 6");
	printf("CAll ===>  %s\n", msg);
	k = (int)MyMalloc(6);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "K FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)k);
	view_mem_stat(msg);
	printf("\n");


	sprintf(msg, "B FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)b);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "D FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)d);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "F FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)f);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "I FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)i);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "B  Alloc 6");
	printf("CAll ===>  %s\n", msg);
	b = (int)MyMalloc(6);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "D  Alloc 17");
	printf("CAll ===>  %s\n", msg);
	d = (int)MyMalloc(17);
	view_mem_stat(msg);
	printf("\n");
	
	sprintf(msg, "I  Alloc 6");
	printf("CAll ===>  %s\n", msg);
	i = (int)MyMalloc(6);
	view_mem_stat(msg);
	printf("\n");
	/*sprintf(msg, "D  Alloc 10");
	printf("CAll ===>  %s\n", msg);
	d = (int)MyMalloc(10);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "F  Alloc 5");
	printf("CAll ===>  %s\n", msg);
	f = (int)MyMalloc(5);
	view_mem_stat(msg);
	printf("\n");
	*/
	



/*
	sprintf(msg, "A Alloc 10");
	printf("CAll ===>  %s\n", msg);
	a = (int)MyMalloc(10);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "B  Alloc 20");
	printf("CAll ===>  %s\n", msg);
	b = (int)MyMalloc(20);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "C  Alloc 13");
	printf("CAll ===>  %s\n", msg);
	c = (int)MyMalloc(13);
	view_mem_stat(msg);
	printf("\n");


	sprintf(msg, "D  Alloc 28");
	printf("CAll ===>  %s\n", msg);
	d = (int)MyMalloc(28);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "E  Alloc 9");
	printf("CAll ===>  %s\n", msg);
	e = (int)MyMalloc(9);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "F  Alloc 25");
	printf("CAll ===>  %s\n", msg);
	f = (int)MyMalloc(25);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "G  Alloc 30");
	printf("CAll ===>  %s\n", msg);
	g = (int)MyMalloc(30);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "A FREE 10");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)a);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "G FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)g);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "C FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)c);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "C  Alloc 12");
	printf("CAll ===>  %s\n", msg);
	c = (int)MyMalloc(11);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "E FREE");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)e);
	view_mem_stat(msg);
	printf("\n");

	sprintf(msg, "F FREE ");
	printf("FREE ===>  %s\n", msg);
	MyFree((int *)f);
	view_mem_stat(msg);
	printf("\n");
	*/

	return 0;
}