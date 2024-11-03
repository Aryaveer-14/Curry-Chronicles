#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2,sum;
	int add (int a, int b);
	clrscr();
    	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	sum=add(n1,n2);
	printf("Sum=%d",sum);
	getch();
}
int add (int a, int b)
{
	int c;
	c=a+b;
	return c;
}
