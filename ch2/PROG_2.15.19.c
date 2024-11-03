#include<stdio.h>
#include<conio.h>
void main ()
{
	int a;
	float b;
	clrscr();
	printf("Enter a float number:");
	scanf("%f",&b);
	a=(int)b;
	printf("The integer part of the number is:%d",a);
	getch();
}
