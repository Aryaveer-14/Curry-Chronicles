#include<stdio.h>
#include<conio.h>
void main()
{
	int m,n,i,j,a[10][10];
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
	printf("The entered matrix is:\n");
	for(i=0;i<=m-1;i++)
	{
		for(j=0;j<=n-1;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	getch();
}