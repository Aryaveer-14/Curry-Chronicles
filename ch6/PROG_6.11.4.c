#include<conio.h>
#include<stdio.h>
struct hockey
{
	char name[20];
	int matches,goals;
};
void main ()
{
	struct hockey s[100],temp;
	int n,i,j;
	clrscr();
	printf("Enter the number of hockey players:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter the player's name, matches played and goals scored:");
		scanf("%s %d %d",s[i].name, &s[i].matches, &s[i].goals);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(s[j].goals<s[j+1].goals)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	printf("Name\t\tMatches\tGoals\n");
	printf("----------------------------------\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%s %d %d\n",s[i].name,s[i].matches,s[i].goals);
	}
	getch();
}