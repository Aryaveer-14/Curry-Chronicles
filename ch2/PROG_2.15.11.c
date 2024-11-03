#include<stdio.h>
#include<conio.h>
void main ()
{
	float r, area;
	clrscr();
	printf("Enter the radius of a circle:");
	scanf("%f",&r);
	area=3.14 *r*r;
	printf("The area is equal:%f",area);
	getch();
}
