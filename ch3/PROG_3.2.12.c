#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,fact=1;
	float sum=0.0;
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
		sum=sum+1.0/fact;
	}
	printf("The value of the series is:%f",sum);
	getch();
}
