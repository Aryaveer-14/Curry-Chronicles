#include<stdio.h>
#include<conio.h>
void main()
{
	int m,n,i,j,a[10][10];
	void transpose (int a[10][10],int m, int n);
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
	printf("The original Matrix is:\n");
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	transpose(a,m,n);
	getch();
}
void transpose (int a[10][10], int m, int n)
{
	int i,j,temp;
	for(i=0;i<=m-1;i++)
	{
		for(j=i;j<=n-1;j++)
		{
		       temp=a[j][i];
		       a[j][i]=a[i][j];
		       a[i][j]=temp;
		}
	}
	printf("The transpose of this matrix is:\n");
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
