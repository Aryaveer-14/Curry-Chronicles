#include<stdio.h>
#include<conio.h>
void main()
{
	int a,*p;
	clrscr();
     	a=125;
	p=&a;
	printf("%d\n",a);
	printf("%x\n",p);
	printf("%d\n",*p);
	getch();
}
