#include<stdio.h>
#include<conio.h>
void main()
{
	int n1,n2,lcm;
	clrscr();
     	printf("Enter two numbers:");
	scanf("%d %d",&n1,&n2);
	if (n1>n2)
	lcm=n1;
	else lcm=n2;
	while(lcm%n1!=0 || lcm%n2!=0)
	{
		lcm++;
	}
	printf("LCM= %d",lcm);
	getch();
}
