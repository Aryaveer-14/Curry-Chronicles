#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
	clrscr();
	printf("Enter the value of n:");
	scanf("%d",&n);
	i=1;
	while(i<=n)
	{
		printf("%d\n",i);
		i++;
	}
	getch();
}
