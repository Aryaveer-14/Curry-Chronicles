#include<stdio.h>
#include<conio.h>
void main()
{
	int n,digit,sum=0,product=1;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&n);
	while(n!=0)
	{
		digit=n%10;
		sum=sum+digit;
		product=product*digit;
		n=n/10;
	}
	printf("Sum=%d\nProduct=%d\n",sum,product);
	getch();
}
