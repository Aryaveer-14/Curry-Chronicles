#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int n,i,a[100],sum=0;
     	float avg,sum1=0,sd;
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
		sum=sum+a[i];
	}
	avg=sum;
	avg=avg/n;
	for(i=0;i<=n-1;i++)
	{
		sum1 = sum1 + pow(a[i]-avg,2);
	}
	sd = sum1/n;
	sd = pow(sd,0.5);
	printf("The standard deviation is %f",sd);
	getch();
}