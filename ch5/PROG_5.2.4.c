#include<stdio.h>
#include<conio.h>
void main()
{
	int no,factorial;
	int fact (int no);
	clrscr();
	printf("Enter a number:");
	scanf("%d",&no);
	factorial=fact(no);
	printf("Factorial=%d",factorial);
	getch();
}
int fact (int no)
{
	int i,ans;
	for(i=1,ans=1;i<=no;i++)
	{
		ans=ans*i;
	}
	return ans;
}
