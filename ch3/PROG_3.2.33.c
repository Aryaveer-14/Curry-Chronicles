#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
	clrscr();
	printf("Enter the value of n:");
	scanf("%d",&n);
	i=1;
	do
	{
		printf("%d\n",i);
		i++;
	}while(i<=n);
	getch();
}
