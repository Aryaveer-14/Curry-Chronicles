#include<conio.h>
#include<stdio.h>
void main()
{
	int n=0,i,j,k;
     	char a[100],rev[100];
	clrscr();
	printf("Enter a string:");
	gets(a);
	while(a[n]!='\0')
	{
		n++;
	}
	for(i=0,j=0;i<=n;i++)
	{
		if(a[i]==' '|| a[i]=='\0')
		{
			for(k=0;j<=i;k++,j++)
			{
				rev[n-i+k]=a[j];
			}
		}
	}
	rev[k-1]=' ';
	rev[n]='\0';
	printf("The reversed sentence is: %s",rev);
	getch();
}
