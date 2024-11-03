#include<conio.h>
#include<stdio.h>
struct employee
{
	char name[20];
	int salary,exp,number;
};
void main ()
{
	struct employee e[100];
	int i;
	clrscr();
	for(i=0;i<=9;i++)
	{
		printf("Enter the employee's name, number, exp and salary");
		scanf("%s %d %d %d",e[i].name,&e[i].number,&e[i].exp,&e[i].salary);
	}
	printf("\nEmployee list with 5+ years experience and salary 10000 or less\nName\tNumber\n");
	printf("--------------------------\n");
	for(i=0;i<=9;i++)
	{
		if(e[i].exp>=5 && e[i].salary<10000)
		printf("%s\t%d\n",e[i].name,e[i].number);
	}
	getch();
}
