#include<stdio.h>
#include<math.h>
#include<conio.h>
void main()
{
	int i,fact=1,N,sign=-1;
	float x,numerator,sum,term;
	float SUMFUN(float x, int N);
	clrscr();
	printf("Enter the value of x and N: ");
	scanf("%f %d",&x,&N);
	sum=SUMFUN(x,N);
	printf("The value of the series is %f",sum);
	getch();
}
float SUMFUN(float x, int N)
{
	int i,fact=1,sign=-1;
	float numerator,sum,term;
	term=x;
	sum=term;
	for(i=3;i<=N;i=i+2)
	{
		fact=fact*i*(i-1);
		numerator=pow(x,i);
		term=numerator/fact;
		sum=sum + sign * term;
		sign=sign*-1;
	}
	return(sum);
}
