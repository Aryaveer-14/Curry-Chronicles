#include<conio.h>
#include<stdio.h>
struct employee
{
	char name[20];
	int salary,code;
	struct
	{
		int date,month,year;
	}date_joining;
};
void main ()
{
	struct employee e[100];
	int i;
	clrscr();
	for(i=0;i<=9;i++)
	{
		printf("Enter the employee's name, code, salary and date of joining as date, month and year separately:");
		scanf("%s %d %d %d %d %d",e[i].name,&e[i].code,&e[i].salary,&e[i].date_joining.date,&e[i].date_joining.month,&e[i].date_joining.year);
	}
	printf("\nEmployee list\nName\tCode\tSalary\tDate of joining\n");
	printf("---------------------------------------------------\n");
	for(i=0;i<=9;i++)
	{
		printf("%s\t%d\t%d\t%d/%d/%d\n",e[i].name,e[i].code,e[i].salary,e[i].date_joining.date,e[i].date_joining.month,e[i].date_joining.year);
	}
	getch();
}
