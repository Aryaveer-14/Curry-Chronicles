#include<stdio.h>
#include<conio.h>
void main ()
{
	int a, b, c, sum;
	float avg;
	clrscr();
	printf("Enter three numbers:");
	scanf("%d %d %d",&a,&b,&c);
	sum= a+b+c;
	avg=sum/3.0;
	printf("The average is equal to:%f",avg);
	getch();
}
