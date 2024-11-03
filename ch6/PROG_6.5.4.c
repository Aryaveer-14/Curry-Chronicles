#include<stdio.h>
#include<conio.h>
void main()
{
	int n=0;
     	char a[100];
	void reverse (char a[100], int n);
	clrscr();
	printf("Enter a string:");
	gets(a);
	while(a[n]!='\0')
	{
		n++;
	}
	reverse(a,n);
	getch();
}
void reverse (char a[100], int n)
{
	int i;
	char temp;
	for(i=0;i<=(n-1)/2;i++)
	{
		temp=a[n-i-1];
		a[n-i-1]=a[i];
		a[i]=temp;
	}
	printf("The reverse of this string is: %s",a);
}
