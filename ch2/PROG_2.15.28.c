#include<stdio.h>
#include<conio.h>
void main ()
{
	int k=3,l=4,m;
	clrscr();
	m=++k +l--;
	printf("Value of m %d\n",m);
	m=k++ + --l;
	printf("Value of m %d\n",m);
	getch();
}
