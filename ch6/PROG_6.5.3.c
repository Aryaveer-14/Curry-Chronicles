#include<conio.h>
#include<stdio.h>
#include<string.h>
void main()
{
	int l;
     	char a[100];
	clrscr();
	printf("Enter a string\n");
	gets(a);
	strrev(a);
	printf("The reversed string is: %s",a);
	getch();
}
