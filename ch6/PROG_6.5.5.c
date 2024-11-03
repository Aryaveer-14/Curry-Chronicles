#include<stdio.h>
#include<conio.h>
void main()
{
	int n=0,i;
	char a[100],temp;
	clrscr();
	printf("Enter a string:");
	gets(a);
	while(a[n]!='\0')
	{
		n++;
	}
	for(i=0;i<=(n-1)/2;i++)
	{
		temp=a[n-i-1];
		a[n-i-1]=a[i];
		a[i]=temp;
	}
	printf("The reverse of this string is: %s",a);
	getch();
}