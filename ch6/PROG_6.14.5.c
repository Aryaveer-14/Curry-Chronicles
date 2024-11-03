#include<stdio.h>
#include<conio.h>
void main ()
{
	int *p,i,a[10];
	clrscr();
     	p=&a;
	printf("Enter 10 nos.\n");
	for(i=0;i<=9;i++)
	scanf("%d",(p+i));
	for(i=0;i<=9;i++)
	printf("%d\n",*(p+i));
	getch();
}
