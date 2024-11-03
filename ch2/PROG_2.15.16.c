#include<stdio.h>
#include<conio.h>
void main ()
{
	int a, rem1, rem2;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&a);
	rem1=a%2;
	rem2=a%3;
	printf("Remainder after dividing by 2 and 3 are %d and %d respectively", rem1, rem2);
	getch();
}
