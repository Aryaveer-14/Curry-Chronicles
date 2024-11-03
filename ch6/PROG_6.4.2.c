#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	char a[100],b[100];
	clrscr();
     	printf("Enter a string\n");
	gets(a);
	strcpy(b,a);
	printf("The new string is %s",b);
	getch();
}
