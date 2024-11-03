#include<stdio.h>
#include<conio.h>
void main()
{
	int a,*p,**p1;
	clrscr();
	a=125;
	p=&a;
	p1=&p;
	printf("%d\n",a);
	printf("%x\n",p);
	printf("%x\n",p1);
	printf("%d\n",*p);
	printf("%x\n",*p1);
	printf("%d\n",**p1);
	getch();
}
