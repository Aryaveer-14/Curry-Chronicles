#include<stdio.h>
#include<conio.h>
void main ()
{
	int a=10,b,c;
	clrscr();
	c=b=a;
	b-=a--;
	c-=--a;
	a-=--a-a--;
	printf("a=%d\nb=%d\nc=%d\n",a,b,c);
	getch();
}