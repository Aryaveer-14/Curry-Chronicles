#include<stdio.h>
#include<conio.h>
void main ()
{
	int a, b;
	clrscr();
	printf("Enter a number to be shifted left:");
	scanf("%d",&a);
	b=a<<3;
	printf("After shifting three times left the value is %d",b);
	getch();
}
