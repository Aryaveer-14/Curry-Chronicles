#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	void prime(int n);
	clrscr();
	printf("Enter a number:");
	scanf("%d",&n);
	prime(n);
	getch();
}
void prime(int n)
{
	int i=2;
	while(n%i!=0)
	{
		i++;
	}
	if(n==i)
	{
		printf("Prime Number");
	}
	else
	{
		printf("Not a prime number");
	}
}
