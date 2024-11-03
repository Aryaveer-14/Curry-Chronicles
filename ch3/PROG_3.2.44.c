#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j,n;
	clrscr();
     	printf("Enter the number of lines:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		for(j=i;j>=1;j--)
		{
			printf("%d",j);
		}
		for(j=1;j<=i-1;j++)
		{
			printf("%c",(j+'A'-1));
		}
		printf("\n");
	}
	getch();
}
