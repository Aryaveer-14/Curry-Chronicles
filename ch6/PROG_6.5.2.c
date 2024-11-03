#include<conio.h>
#include<stdio.h>
void main()
{
	char a[100];
     	int i,len=0,count=0;
	clrscr();
	printf("Enter a string:\n");
	gets(a);
	while(a[len]!=0)
	{
		len++;
	}
	for(i=0;i<=len-1;i++)
	{
		if(a[i]=='a' ||a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
		count++;
	}
	printf("The total number of vowels are: %d",count);
	getch();
}
