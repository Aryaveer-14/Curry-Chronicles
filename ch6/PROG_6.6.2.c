#include<stdio.h>
#include<conio.h>
void main()
{
	char a[12][10]={"January","February","March","April","May", "June","July","August","September","October","November", "December"};
	int m;
	clrscr();
	printf("Enter the month number:");
	scanf("%d",&m);
	printf("The month name is %s",a[m-1]);
	getch();
}
