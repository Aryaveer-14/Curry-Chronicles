#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2;
	void add (int a, int b);
	clrscr();
	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	add(n1,n2);
	getch();
}
void add (int a, int b)
{
	int c;
	c=a+b;
	printf("sum=%d",c);
}
