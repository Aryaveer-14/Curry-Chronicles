#include<stdio.h>
#include<conio.h>
#include<math.h>
void main ()
{
	int a,b,c;
	float x1,x2;
	clrscr();
	printf("Enter the coefficients of the quadratic equation:");
	scanf("%d %d %d",&a,&b,&c);
	x1=(-b+pow((b*b-4*a*c),0.5))/(2*a);
	x2=(-b-pow((b*b-4*a*c),0.5))/(2*a);
	printf("The roots of quadratic equation are:%f and %f",x1,x2);
	getch();
} 
