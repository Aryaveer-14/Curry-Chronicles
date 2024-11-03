#include<stdio.h>
#include<conio.h>
void main()
{
	int n;
	void display (int n);
	clrscr();
	printf("Enter a number: ");
	scanf("%d",&n);
	display(n);
	getch();
}
void display (int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d\n",i);
	}
}
