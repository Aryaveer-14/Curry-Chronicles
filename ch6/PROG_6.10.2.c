#include<conio.h>
#include<stdio.h>
struct cricketer
{
	char name[20];
	int runs, wickets;
};
void main ()
{
	struct cricketer c1;
	clrscr();
	printf("Enter the cricketer's name, runs scored and wickets taken:");
	gets(c1.name);
	scanf("%d %d",&c1.runs,&c1.wickets);
	printf("The cricketer details are as follows:\nName:%s\nRuns scored:%d\nWickets taken:%d\n",c1.name,c1.runs,c1.wickets);
	getch();
}
