#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100];
	void descend (int a[], int n);
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	descend(a,n);
	getch();
}
void descend (int a[], int n)
{
	int i,j,temp;
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("After sorting\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}
