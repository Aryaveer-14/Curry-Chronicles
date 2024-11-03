#include<stdio.h>
#include<conio.h>
void main()
{
	int m,n,i,j,a[10][10],large;
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
	large=a[0][0];
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			if(large<a[i][j])
			large=a[i][j];
		}
	}
	printf("The largest element in the matrix is %d",large);
	getch();
}