# include<stdio.h>
# include<conio.h>
# include "malloc.h"
struct student
{
int roll_no;
float percentage;
struct student *next;
};

void main()
{
	int i;
	struct student s[10];
	struct student p;
	float dummy;
	clrscr();
	for(i=0;i<=9;i++)
	{
		printf("Enter roll number and percentage of the student:");
		scanf("%d %f",&s[i].roll_no,&dummy);
		s[i].percentage=dummy;
		if(i<9)
		s[i].next=&s[i+1];
		else
		s[i].next=0;
	}
	p.next=&s[0];
	printf("Roll No.\tPercentage\n");
	while(p.next!=0)
	{
		p=*p.next;
		printf("%d\t\t%f\n",p.roll_no,p.percentage);

	}
	getch();
}
