#include<stdio.h>
#include<conio.h>
void main ()
{
	int n1;
	float n2, result;
	clrscr();
	printf("Enter one integer and one float type number each:");
	scanf("%d %f",&n1,&n2);
	result=n1*n2;
	printf("The product is :%f",result);
	getch();
}
