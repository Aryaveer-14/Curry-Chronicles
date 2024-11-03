#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n,x=1;
	clrscr();
        printf("Enter a number:");
	scanf("%d",&n);
	printf("The following are %d prime numbers\n",n);
	while (n!=0)
	{
		x++;
		i=2;
		while(x%i!=0)
		{
			i++;
		}
		if(x==i)
		{
			printf("%d\n",x);
			n--;
		}
	}
	getch();
}
