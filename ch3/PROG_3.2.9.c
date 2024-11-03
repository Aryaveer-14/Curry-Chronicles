#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,sum=0;
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=sum+i*2;
	}
	printf("Sum= %d\n",sum);
	getch();
}
