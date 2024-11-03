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
	if(strcmp(a,b)==0)
	printf("The strings are equal ");
	else if(strcmp(a,b)>0)
	printf("%s string is greater",a);
	else
	printf("%s string is greater",b);
	getch();
}
