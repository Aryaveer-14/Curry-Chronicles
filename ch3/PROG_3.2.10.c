#include<stdio.h>
#include<conio.h>
void main()
{
	int a=0,b=1,c,i,n;
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	printf("Fibonacci Series\n0\n1\n");
	for(i=1;i<=n-2;i++)
	{
		c=a+b;
		printf("%d\n",c);
		a=b;
		b=c;
	}
	getch();
}
