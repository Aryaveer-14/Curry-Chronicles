#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i;
	int fibo (int ,int ,int);
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("0\n");
	for(i=1;i<=n-1;i++)
	{
		printf("%d\n",fibo(0,1,i));
	}
	getch();
}
int fibo (int a, int b, int i)
{
	if(i==1)
	return b;
	else
	return (fibo(b,a+b,--i));
}
