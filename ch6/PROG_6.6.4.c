#include<stdio.h>
#include<conio.h>
void main()
{
	int m,n,i,j,a[10][10],b[10];
	clrscr();
     	printf("Enter the number of rows and columns of matrix:");
	scanf("%d %d",&m,&n);
	printf("Enter the values of matrix\n");
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("Enter a value:");
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<=n-1;i++)
	{
		b[i]=0;
		for(j=0;j<=m-1;j++)
		{
			b[i]=b[i]+a[j][i];
		}
	}
	printf("The entered matrix is:\n");
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("The sum of the columns are:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\t",b[i]);
	}
	getch();
}