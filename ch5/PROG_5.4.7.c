#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	void pattern(int n);
	clrscr();
	printf("Enter the number of lines:");
	scanf("%d",&n);
	pattern(n);
	getch();
}
void pattern(int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
