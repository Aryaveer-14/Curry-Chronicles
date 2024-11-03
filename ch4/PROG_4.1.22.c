#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2,lcm,gcd;
	clrscr();
     	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	if (n1>n2)
	{
		lcm=n1;
		gcd=n2;
	}
	else
	{
		lcm=n2;
		gcd=n1;
	}
	while(lcm%n1!=0 || lcm%n2!=0)
	{
		lcm++;
	}
	while(n1%gcd!=0 || n2%gcd!=0)
	{
		gcd--;
	}
	printf("LCM= %d \nGCD=%d",lcm,gcd);
	getch();
}
