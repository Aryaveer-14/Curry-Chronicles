#include<stdio.h>
#include<conio.h>
void main()
{
	int sum,digit,x=99,copy,n;
	clrscr();
     	printf("Enter a number:");
	scanf("%d",&n);
	printf("The list of %d Armstrong number is given below\n",n);
	while(n!=0)
	{
		x++;
		copy=x;
		sum=0;
		while(x!=0)
		{
			digit=x%10;
			sum=sum+digit*digit*digit;
			x=x/10;
		}
		if(sum==copy)
		{
			printf("%d\n",copy);
			n--;
		}
		x=copy;
	}
	getch();
}
