#include<conio.h>
#include<stdio.h>
void main()
{
	char a[100];
     	int i,len=0,vowels=0,spaces=0,digits=0,consonants=0;
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
		vowels++;
		else
		{
			if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
			consonants++;
			else
			{
				if(a[i]>='0' &&a[i]<='9')
				digits++;
				else
				{
					if(a[i]==' ')
					spaces++;
				}
			}
		}
	}
	printf("The total number of vowels are: %d\nThe total number of spaces are:%d\nThe total number of digits are: %d\nThe total number of consonants are: %d", vowels,spaces,digits,consonants);
	getch();
}