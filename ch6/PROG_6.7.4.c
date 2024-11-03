#include<stdio.h>
#include<conio.h>
int x;
void f1()
{
	++x;
}
void main()
{
	int x = 10;
	f1();
	x = ::x + 10;
	printf("%d %d\n",x,::x);
	getch();
}
