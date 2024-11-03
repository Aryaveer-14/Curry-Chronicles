#include<stdio.h>
#include<conio.h>
void main()
{
	int n,reverse=0,digit;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&n);
	while(n!=0)
	{
		digit=n%10;
		n=n/10;
		reverse=reverse*10+digit;
	}
	printf("The reverse number is:%d",reverse);
	getch();
}
