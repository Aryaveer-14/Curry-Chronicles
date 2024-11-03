#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100],sum1=0,sum2=0,sum;
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		sum1 = sum1 + a[i] * a[i];
		sum2 = sum2 +a[i];
	}
	sum = sum1 - sum2 * sum2;
	printf("The value of the series is %d",sum);
	getch();
}
