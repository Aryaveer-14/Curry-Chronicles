#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
	int i, fact=1,sign=-1;
	float x,numerator,sum,term;
	clrscr();
	printf("Enter an angle in degrees: ");
	scanf("%f",&x);
	x=x*3.14/180;
	term=x;
	sum=term;
	for(i=3;term>=0.0000001;i=i+2)
	{
		fact=fact*i*(i-1);
		numerator=pow(x,i);
		term=numerator/fact;
		sum=sum + sign * term;
		sign=sign*-1;
	}
	printf("The value of the series is:%f",sum);
	getch();
}
