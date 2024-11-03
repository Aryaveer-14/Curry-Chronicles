#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100],even=0;
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	for(i=0;i<=n-1;i++)
	{
		if (a[i]%2==0)
		even++;
	}
	printf("The count of even numbers is %d and that of odd numbers is %d",even,(n-even));
	getch();
} 
