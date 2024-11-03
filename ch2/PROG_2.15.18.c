#include<stdio.h>
#include<conio.h>
void main ()
{
	int a, rem;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&a);
	rem=a%2;
	(rem==0)?printf("Even number"):printf("Odd number");
	getch();
}
