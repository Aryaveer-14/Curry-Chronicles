#include<stdio.h>
#include<conio.h>
void main()
{
	int n,r,npr;
	int fact (int no);
	clrscr();
	printf("Enter the values of n and r:");
	scanf("%d %d",&n,&r);
	npr=fact(n)/fact(n-r);
	printf("nPr=%d",npr);
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
