#include<stdio.h>
#include<conio.h>
void main()
{
	int no,sum;
	int recursion (int no);
	clrscr();
	printf("Enter a number:");
	scanf("%d",&no);
	sum=recursion(no);
	printf("Sum of numbers from 1 to n is %d",sum);
	getch();
}
int recursion (int no)
{
	if(no==1)
	return 1;
	else
	return (no + recursion (no-1));
}
