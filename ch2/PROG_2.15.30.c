#include<stdio.h>
#include<conio.h>
void main ()
{
	int a=1,b=2,c=3,d=4.75,x;
	clrscr();
	x=++a + b++ * ++c % d++;
	printf("%d %d %d %d %d",a,b,c,d,x);
	getch();
}
