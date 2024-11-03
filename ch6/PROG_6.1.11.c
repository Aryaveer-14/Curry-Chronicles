#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100],x,index;
	int search (int a[], int n, int x);
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&x);
	index=search(a,n,x);
	if(index==n)
	printf("Not Found");
	else
	printf("The element %d is found in the index %d",x,index);
	getch();
}
int search (int a[], int n, int x)
{
	int i;
	for(i=0;i<=n-1;i++)
	{
		if(x==a[i])
		break;
	}
	return i;
}