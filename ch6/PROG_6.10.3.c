#include<stdio.h>
#include<conio.h>
#include<stdio.h>
struct hockey
{
	char name[20];
	int matches, goals;
};
void main ()
{
	struct hockey c1;
	clrscr();
	printf("Enter the hockey player's name, matches played and goals scored:");
	gets(c1.name);
	scanf("%d %d",&c1.matches,&c1.goals);
	printf("The hockey player's details are as follows:\nNmae:%s\nMatches played:%d\nGoals scored:%d\n",c1.name,c1.matches,c1.goals);
	getch();
}
