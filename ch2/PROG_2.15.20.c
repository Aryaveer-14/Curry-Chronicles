#include<stdio.h>
#include<conio.h>
void main ()
{
	int a,b;
	clrscr();
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	printf("The AND of %d and %d is %d\n",a,b,(a & b));
	printf("The OR of of %d and %d is %d\n",a,b,(a | b));
	printf("The EXOR of of %d and %d is %d\n",a,b,(a ^ b));
	printf("The NOT of %d is %d\n",a,~a);
	printf("The NOT of %d is %d\n",b,~b);
	getch();
}
