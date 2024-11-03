#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2,gcd;
	clrscr();
     	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	if (n1<n2)
	gcd=n1;
	else gcd=n2;
	while(n1%gcd!=0 || n2%gcd!=0)
	{
		gcd--;
	}
	if(gcd==1)
	printf("GCD doesnt exists");
	else
	printf("GCD=%d",gcd);
	getch();
}
