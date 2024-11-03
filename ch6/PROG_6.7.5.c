#include<stdio.h>
#include<conio.h>
void f1()
{
	extern int n3;
	static int n1;
	int n2 = 20;
	n1 = n1 + 10;
	n2 = n1 + n2;
	n3 = n1 + n2;
	printf("%d %d %d\n",n1,n2,n3);
}
int n3;
void main()
{
	register int i;
	for (i = 1; i <=3; i++) f1();
	getch();
}
