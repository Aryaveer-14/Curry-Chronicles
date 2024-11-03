#include<stdio.h>
#include<conio.h>
void main ()
{
	int a,b,c;
	clrscr();
	a=2;b=5;c=10;
	printf("Value=%d\n",(a+b*-c));
	printf("Value=%d\n",(-c/b*c-a));
	printf("Value=%d\n",(-a+ ++b %a));
	getch();
}
