#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	int n,i;
	clrscr();
     	printf("Enter a number");
	scanf("%d",&n);
	printf("Binary form is:");
	for(i=15;i>=0;i--)
	{
		printf("%d",n/(int)pow(2,i));
		n=n%(int)(pow(2,i));
	}
	getch();
}
