#include<stdio.h>
#include<conio.h>
void main()
{
	int n,total=0,i;
	clrscr();
     	for(i=1;i<=10;i++)
	{
		printf("Enter a number:");
		scanf("%d",&n);
		if(n>99)
		break;
		total=total+n;
	}
	printf("Total=%d",total);
	getch();
}
