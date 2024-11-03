#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,sum=0,n,fact;
	clrscr();
     	printf("Enter a number:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		fact=1;
		for(j=1;j<=(2*i-1);j++)
		{
			fact=fact*j;
		}
		sum=sum+fact;
	}
	printf("The value of this series= %d",sum);
	getch();
}
