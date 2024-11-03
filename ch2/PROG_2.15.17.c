#include<stdio.h>
#include<conio.h>
void main ()
{
	int a, digit1, digit2;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&a);
	digit1=a%10;
	a=a/10;
	digit2=a%10;
	printf("Reversed no is %d%d",digit1,digit2);
	getch();
}
