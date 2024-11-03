#include<conio.h>
#include<stdio.h>
void main()
{
	char a[100];
     	int len=0;
	clrscr();
	printf("Enter a string:\n");
	gets(a);
	while(a[len]!='\0')
	{
		len++;
	}
	printf("The length of this string is %d characters.",len);
	getch();
}
