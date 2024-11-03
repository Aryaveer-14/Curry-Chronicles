#include<stdio.h>
#include<conio.h>
void main()
{
	int i=0,n=1;
	clrscr();
        while(i<10)
	{
		if(n%5==0 && n%8==0)
		{
			printf("%d\n",n);
			i++;
		}
		n++;
	}
	getch();
}
