#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
	int i, n, fact=1,sign=-1;
	float x,numerator,sum,term;
	clrscr();
	printf("Enter an angle in degrees and the value of n:  ");
	scanf("%f %d",&x,&n);
	x=x*3.14/180;
	term=x;
	sum=term;
	for(i=3;i<=n;i=i+2)
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
