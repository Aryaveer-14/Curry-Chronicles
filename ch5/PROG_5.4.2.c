#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
	void mul(int n);
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	mul(n);
	getch();
}
void mul(int n)
{
	int i;
	for(i=1;i<=10;i++)
	{
		printf("%d X %d = %d\n",n,i,(n*i));
	}
}
