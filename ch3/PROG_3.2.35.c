#include<stdio.h>
#include<conio.h>
void main()
{
	int n,digit,sum=0,product=1;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&n);
	do
	{
		digit=n%10;
		sum=sum+digit;
		product=product*digit;
		n=n/10;
	}while(n!=0);
	printf("Sum=%d\nProduct=%d\n",sum,product);
	getch();
}
