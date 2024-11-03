#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,fact;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=1,fact=1;i<=n;i++)
	{
		fact=fact * i;
	}
	printf("Factorial of this number is:%d\n",fact);

}
