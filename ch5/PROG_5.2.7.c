#include<stdio.h>
#include<conio.h>
void main()
{
	int no1,no2,gcd;
	int GCD (int no1, int no2);
	clrscr();
	printf("Enter two numbers:");
	scanf("%d %d",&no1,&no2);
	gcd=GCD(no1,no2);
	if(gcd==1)
	printf("GCD doesnt exist");
	else
	printf("GCD=%d",gcd);
	getch();
}
int GCD (int no1, int no2)
{
	int gcd;
	if(no1<no2)
	gcd=no1;
	else
	gcd=no2;
	while(no1%gcd!=0 || no2%gcd!=0)
	{
		gcd--;
	}
	return gcd;
}