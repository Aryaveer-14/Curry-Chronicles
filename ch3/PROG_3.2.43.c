#include<stdio.h>
#include<conio.h>
void main()
{
	int i,j;
     	char x='P';
	clrscr();
	for(i=1;i<=5;i++)
	{
	       for(j=1;j<=i;j++)
	       {
			printf("%c",(x+j-1));
	       }
	       printf("\n");
	}
	getch();
}
