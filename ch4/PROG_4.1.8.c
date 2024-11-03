#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i;
	clrscr();
        printf("Enter a number:");
	scanf("%d",&n);
	printf("Factors are:\n");
	i=2;
	while(i<n)
	{
		if(n%i==0)
		printf("%d\n",i);
		i++;
	}
	getch();
}
