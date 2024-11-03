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
	l=strlen(a);
	printf("The length of the entered string is: %d",l);
	getch();
}
