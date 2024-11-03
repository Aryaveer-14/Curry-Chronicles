#include<conio.h>
#include<stdio.h>
struct cricketer
{
	char name[20];
	int matches,runs;
};
void main ()
{
	struct cricketer s[100],temp;
	int n,i,j;
	clrscr();
	printf("Enter the number of cricketers:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter the player's name, matches played and runs scored:");
		scanf("%s %d %d",s[i].name,&s[i].matches,&s[i].runs);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(s[j].runs<s[j+1].runs)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	printf("Name\t\tMatches\tRuns\n");
	printf("----------------------------------\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%s\t%d\t%d\n",s[i].name,s[i].matches,s[i].runs);
	}
	getch();
}