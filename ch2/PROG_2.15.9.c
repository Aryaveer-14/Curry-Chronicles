#include<stdio.h>
#include<conio.h>
void main ()
{
	int n1, n2, greater;
	clrscr();
	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	greater=(n1>n2)?n1:n2;
	printf("The larger number is :%d",greater);
	getch();
}
