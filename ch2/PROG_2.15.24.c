#include<stdio.h>
#include<conio.h>
void main ()
{
	int x=4,y=9;
	int z;
	clrscr();
	z=(x++)+(--y)+y;
	printf("Value=%d\n",z);
	z=(--x)+x+(y--);
	printf("Value=%d\n",z);
	getch();
}
