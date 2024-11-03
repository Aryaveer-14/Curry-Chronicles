#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100],sum=0;
     	float avg;
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
		sum=sum+a[i];
	}


	avg=sum;
	avg=avg/n;

	printf("The average of the numbers entered is %f",avg);
	getch();
}
