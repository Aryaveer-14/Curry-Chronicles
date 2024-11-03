#include<stdio.h>
#include<conio.h>
void main()
{
	int sum=0,digit,x,copy;
	clrscr();
        printf("Enter a number:");
	scanf("%d",&x);
	copy=x;
	while(x!=0)
	{
		digit=x%10;
		sum=sum+digit*digit*digit;
		x=x/10;
	}
	if(sum==copy)
	{
		printf("Armstrong Number");
	}
	else
	{
		printf("Not an Armstrong Number");
	}
	getch();
}
