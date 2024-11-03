#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct hockey
{
	char name[20],country[20];
	int matches,goals;
};
void main ()
{
	struct hockey s[100],temp;
	int n,i,j,k;
	clrscr();
	printf("Enter the number of hockey players:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter the player's name, country, matches played and goals scored:");
		scanf("%s %s %d %d",s[i].name,s[i].country,&s[i].matches,&s[i].goals);
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
	printf("\nList according to goals scored\nName\t\tCountry\tMatches\tGoals\n");
	printf("------------------------------------------\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%s\t%s\t%d\t%d\n",s[i].name,s[i].country,s[i].matches,s[i].goals);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(s[j].matches<s[j+1].matches)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	printf("\nList according to matches played\nName\t\tCountry\tMatches\tGoals\n");
	printf("------------------------------------------\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%s\t%s\t%d\t%d\n",s[i].name,s[i].country,s[i].matches,s[i].goals);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			for(k=0;s[j].name[k]!='\0';k++)
			{
				if(s[j].name[k]!=s[j+1].name[k])
				{
					if(s[j].name[k]>s[j+1].name[k])
					{
						temp=s[j];
						s[j]=s[j+1];
						s[j+1]=temp;
					}
					break;
				}
			}
		}
	}
	printf("\nList according to Name\nName\t\tCountry\tMatches\tGoals\n");
	printf("------------------------------------------\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%s\t%s\t%d\t%d\n",s[i].name,s[i].country,s[i].matches,s[i].goals);
	}
	for(i=0;i<=n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			for(k=0;s[j].name[k]!='\0';k++)
			{
				if(s[j].country[k]!=s[j+1].country[k])
				{
					if(s[j].country[k]>s[j+1].country[k])
					{
						temp=s[j];
						s[j]=s[j+1];
						s[j+1]=temp;
					}
					break;
				}
			}
		}
	}
	printf("\nList according to Country\nName\t\tCountry\tMatches\tGoals\n");
	printf("------------------------------------------\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%s\t%s\t%d\t%d\n",s[i].name,s[i].country,s[i].matches,s[i].goals);
	}
	getch();
}
