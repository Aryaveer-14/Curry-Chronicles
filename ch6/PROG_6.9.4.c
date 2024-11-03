#include<stdio.h>
#include<conio.h>
void main()
{
	int i,a[2]={10,20};
	clrscr();
     	for(i=0;i<=1;i++)
	{
		printf("%d\n",a[i]);
		printf("%d\n",*(a+i));
		printf("%d\n",*(i+a));
	}
	getch();
}
