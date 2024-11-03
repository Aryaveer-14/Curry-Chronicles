#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n;
	float sum=0.0;
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum=sum+1.0/i;
	}
	printf("The value of the series is:%f",sum);
	getch();
}