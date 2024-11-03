#include<stdio.h>
#include<conio.h>
void main ()
{
	int x=1;
	clrscr();
	printf("%d%d%d\n",x,(x=x+2),(x<<2));
	x<<2;
	printf("%d%d%d\n",++x,x++,++x);
	getch();
}
