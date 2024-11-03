//Program 3.2 : This is a simple program to calculate the square of a number
#include<stdio.h>
#include<conio.h>
void main ()
{
	clrscr();
	int x, y;
	printf("Enter a number:");
	scanf("%d",&x);
	y=x*x;
	printf("The square of %d is %d",x,y);
	getch();
}
