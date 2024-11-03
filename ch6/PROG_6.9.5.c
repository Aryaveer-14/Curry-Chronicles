#include<stdio.h>
#include<conio.h>
void main()
{
	int a,b;
	void sum (int *p1, int *p2);
	clrscr();
	printf("Enter two numbers");
	scanf("%d %d",&a,&b);
	sum(&a,&b);
	getch();
}
void sum (int *p1, int *p2)
{
	int c;
	c=*p1+*p2;
	printf("The sum is equal to %d",c);
}
