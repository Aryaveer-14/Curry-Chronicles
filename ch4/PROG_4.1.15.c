#include<stdio.h>
#include<conio.h>
void main()
{
	int marks;
	clrscr();
     	printf("Enter the marks out of 100:");
	scanf("%d",&marks);
	if(marks==100)
	printf("Distinction");
	else
	{
		switch(marks/10)
		{
			case 0:
			case 1:
			case 2:
			case 3:	printf("Fail");
			break;
			case 4:printf("Pass Class");
			break;
			case 5:printf("Second Class");
			break;
			case 6:printf("First Class");
			break;
			case 7:
			case 8:
			case 9:printf("Distinction");
			break;
			default:printf("Invalid marks");
		}
	}
	getch();
}
