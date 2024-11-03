#include<conio.h>
#include<stdio.h>
void main()
{
	int n,i,a[100],temp;
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value");
		scanf("%d",&a[i]);
	}
	temp=a[n-1];
	for(i=n-1;i>0;i--)
	{
		a[i]=a[i-1];
	}
	a[0]=temp;
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}
