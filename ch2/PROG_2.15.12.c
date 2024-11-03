#include<stdio.h>
#include<conio.h>
void main ()
{
	float f, c;
	clrscr();
	printf("Enter the temperature in fahrenheit:");
	scanf("%f",&f);
	c=(f-32)/1.8;
	printf("The temperature in degree celsius is equal:%f",c);
	getch();
}