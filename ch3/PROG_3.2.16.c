#include<stdio.h>
#include<conio.h>
void main()
{
	int t;
	float s,s0,v0,a;
	clrscr();
	printf("Enter the values of s0, v0 and a: ");
	scanf("%f %f %f",&s0,&v0,&a);
	printf("t\tS\n1\t%d\n",s0+v0+0.5*a);
	for(t=5;t<=100;t+=5)
	{
		printf("%d\t%f\n",t,s0+v0+0.5*a*t*t);
	}
	getch();
}
