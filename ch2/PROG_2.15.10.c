#include<stdio.h>
#include<conio.h>
void main ()
{
	int n1, n2, n3, greater;
	clrscr();
	printf("Enter three numbers:");
	scanf("%d %d %d", &n1,&n2,&n3);
	greater=(n1>n2)?((n1>n3)?n1:n3):((n2>n3)?n2:n3);
	printf("The largest number is :%d",greater);
	getch();
}

