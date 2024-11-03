#include<stdio.h>
#include<conio.h>
void main()
{
	int a,*a1;
	float b,*b1;
	clrscr();
	a1=&a;
	b1=&b;
	printf("%x \n%x\n",a1,b1);
	a1++;
	b1++;
	printf("%x \n%x\n",a1,b1);
	getch();
}
