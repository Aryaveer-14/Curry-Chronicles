#include<stdio.h>
#include<conio.h>
void main()
{
	int n,countBefore=0,countAfter=0;
	float x;
	clrscr();
	printf("Enter a number:");
	scanf("%f",&x);
	n=(int)(x);
	x=x-n;
	while(n!=0)
	{
		n=n/10;
		countBefore++;
	}
	while(x!=0)
	{
		x=x*10;
		n=(int)x;
		x=x-n;
		countAfter++;
	}
	printf("Number of digits before decimal point=%d\n",countBefore);
	printf("Number of digits before decimal point=%d",countAfter);
	getch();
}
