#include<stdio.h>
#include<conio.h>
void main ()
{
	int a;
	clrscr();
	printf("Enter a number:");
	scanf("%d",&a);
	printf("This is ASCII value of: %c",(char)a);
	getch();
}
