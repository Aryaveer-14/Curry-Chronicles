#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	char a[100],b[100];
	clrscr();
     	printf("Enter two strings:\n");
	gets(a);
	gets(b);
	strcat(a,b);
	printf("The concatenated string is %s",a);
	getch();
}
