#include<stdio.h>
#include<conio.h>
void main()
{
	int m,n,i,j,a[10][10];
	void transpose (int a[10][10],int m, int n);
	clrscr();
     	printf("Enter the number of rows and columns:");
	scanf("%d %d",&m,&n);
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("Enter a value:");
			scanf("%d",&a[i][j]);
		}
	}
	printf("The original Matrix is:\n");
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d \t",a[i][j]);
		}
		printf("\n");
	}
	transpose(a,m,n);
	getch();
}
void transpose (int a[10][10], int m, int n)
{
	int b[10][10],i,j;
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			b[j][i]=a[i][j];
		}
	}
	printf("The transpose of this matrix is:\n");
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=m-1;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
}
