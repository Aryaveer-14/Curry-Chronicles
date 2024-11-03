#include<stdio.h>
#include<conio.h>
void main()
{
	int n,total=0;
	clrscr();
     again:
	printf("Enter a number:");
	scanf("%d",&n);
	total=total+n;
	if(total<100)
	goto again;
	printf("Total=%d",total);
	getch();
}
