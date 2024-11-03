#include<stdio.h>
#include<conio.h>
void main()
{
	int largest (int a[], int n);
	int n,i,a[100],large;
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	large=largest(a,n);
	printf("The largest number is %d",large);
	getch();
}
int largest (int a[], int n)
{
	int i,large;
	large=a[0];
	for(i=1;i<=n-1;i++)
	{
		if(large<a[i])
		large=a[i];
	}
	return large;
}
