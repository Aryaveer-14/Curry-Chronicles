#include<conio.h>
#include<stdio.h>
union info
{
	char name[20];
	long id;
};
void main ()
{
	union info i1;
     	int choice;
	clrscr();
	printf("Enter your information\n1. Name\n2.ID number\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:	printf("Enter your name:");
			scanf("%s",i1.name);
			break;
		case 2:	printf("Enter your ID number:");
			scanf("%ld",&i1.id);
			break;
		default:printf("Invalid Choice");
	}
	if(choice==1)
	printf("Your Name entered is %s",i1.name);
	else if(choice==2)
	printf("Your ID number entered is %ld",i1.id);
	getch();
}
