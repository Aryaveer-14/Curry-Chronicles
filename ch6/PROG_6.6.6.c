#include<stdio.h>
#include<conio.h>
void main()
{
	int n=0;
	char a[100],b[100];
	void copy (char a[100], char *p, int n);
	void join (char a[100], char *p, int n, int m);
	clrscr();
	printf("Enter a string:");
	gets(a);
	while(a[n]!='\0')
	{
		n++;
	}
	copy(a,&b[0],n);
	printf("New string after copy is %s\n",b);
	join(a,&b[0],n,n);
	printf("New string after concatenation is %s\n",b);
	getch();
}
void copy (char a[100], char *p, int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		*(p+i)=a[i];
	}
}
void join (char a[100], char *p, int n, int m)
{
	int i;
	for(i=n;i<=m+n;i++)
	{
		*(p+i)=a[i-n];
	}
}
