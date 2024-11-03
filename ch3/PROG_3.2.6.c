#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",2*i+1);
	}
	getch();
}