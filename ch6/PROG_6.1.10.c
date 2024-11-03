#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,a[100];
	void reverse (int a[], int n);
	clrscr();
     	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	reverse(a,n);
	getch();
}
void reverse (int a[], int n)
{
	int i,temp;
	for(i=0;i<=(n-1)/2;i++)
	{
		temp=a[n-i-1];
	    	a[n-i-1]=a[i];
    		a[i]=temp;
	}
	printf("The reverse of this array is:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
}
