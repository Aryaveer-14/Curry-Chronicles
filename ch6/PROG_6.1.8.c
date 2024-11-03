#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100],small;
	int smallest (int a[], int n);
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	small=smallest(a,n);
	printf("The smallest number is %d",small);
	getch();
}
int smallest (int a[], int n)
{
	int i,small;
	small=a[0];
	for(i=1;i<=n-1;i++)
	{
		if(small>a[i])
		small=a[i];
	}
	return small;
}