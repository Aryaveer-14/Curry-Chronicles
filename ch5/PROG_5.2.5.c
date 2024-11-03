#include<stdio.h>
#include<conio.h>
void main()
{
	int n,r,ncr;
	int fact (int no);
	clrscr();
	printf("Enter the values of n and r:");
	scanf("%d %d",&n,&r);
	ncr=fact(n)/(fact(r)*fact(n-r));
	printf("nCr=%d",ncr);
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
