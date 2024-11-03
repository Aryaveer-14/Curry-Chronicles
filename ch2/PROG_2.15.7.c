#include<stdio.h>
#include<conio.h>
void main ()
{
	int d1, d2, d3, number;
	clrscr();
	printf("Enter a three digit number:");
	scanf("%d",&number);
	d3=number%10;
	number=number/10;
	d2= number%10;
	number =number / 10;
	d1=number%10;
	printf("The digits are :%d\n%d\n%d",d1,d2,d3);
	getch();
}
