#include<stdio.h>
#include<conio.h>
void main ()
{
	float rateOfInterest, years, principal, simpleInterest;
	clrscr();
	printf("Enter the principal amount, rate of interest and no. of years:");
	scanf("%f%f%f", &principal, &rateOfInterest, &years);
	simpleInterest = principal * rateOfInterest*years / 100;
	printf("The simple interest is %f", simpleInterest) ;
	getch();
}
