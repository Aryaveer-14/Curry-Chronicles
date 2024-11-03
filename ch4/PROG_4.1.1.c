#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	clrscr();
        printf("Enter a number:");
	scanf("%d",&n);
	if(n%10==0)
	{
		printf("The number is divisible by 10");
	}
	else
	{
		printf("The number is not divisible by 10");
	}
	getch();
}
