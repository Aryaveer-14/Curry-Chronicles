#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
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
	for(i=1;i<=n;i+=2)
	{
		printf("%d\n",i);
	}
}
