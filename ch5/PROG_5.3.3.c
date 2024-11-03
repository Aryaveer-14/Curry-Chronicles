#include<stdio.h>
#include<conio.h>
void main()
{
	int n,x,y;
	int exponential (int x, int n);
	clrscr();
	printf("Enter the values of x and n:");
	scanf("%d %d",&x,&n);
	y=exponential(x,n);
	printf("The value of x raise to n is %d",y);
	getch();
}
int exponential (int x, int n)
{
	if(n==1)
	return x;
	else
	return (x*exponential(x,n-1));
}