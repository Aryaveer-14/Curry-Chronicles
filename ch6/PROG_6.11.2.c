#include<conio.h>
#include<stdio.h>
struct cricketer
{
	char name[20];
	int runs, wickets;
};
void main ()
{
	struct cricketer c[100];
	int n,i;
	clrscr();
	printf("Enter the number of cricketers");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter the cricketer's name, runs scored and wickets taken:");
		scanf("%s %d %d",c[i].name,&c[i].runs,&c[i].wickets);
	}
		printf("Name\tRuns\tWickets\n");
		printf("-----------------------------------\n");
		for(i=0;i<=n-1;i++)
	{
		printf("%s\t%d\t%d\n",c[i].name,c[i].runs,c[i].wickets);
	}
	getch();
}
