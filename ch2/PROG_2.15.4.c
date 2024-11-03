#include<stdio.h>
#include<conio.h>
void main ()
{
	float basic,hra,da,gross;
	clrscr();
	printf("Enter the basic salary:");
	scanf("%f", &basic);
	hra=40*basic/100;
	da = 50*basic/100;
	gross=basic+da+hra;
	printf("The total salary is %f",gross);
	getch();
}
