#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	void odd(int n);
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	odd(n);
	getch();
}
void odd(int n)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",2*i+1);
	}
}
