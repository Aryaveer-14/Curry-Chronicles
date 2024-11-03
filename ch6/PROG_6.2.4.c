#include<stdio.h>
#include<conio.h>
void main()
{
	int m,n,i,j,a[10][10],sum=0;
	clrscr();
     	printf("Enter the number of rows / columns:");
	scanf("%d",&m);
	n=m;
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("Enter a value:");
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(i==j)
			sum+=a[i][j];
		}
	}
	printf("The sum of diagonal elements is %d",sum);
	getch();
}
