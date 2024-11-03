#include<stdio.h>
#include<conio.h>
void main()
{
	int no1,no2,result;
	char choice;
	clrscr();
	printf("Enter the operation to be performed:");
	scanf("%d",&no1);
	choice=getche();
	scanf("%d",&no2);
	switch(choice)
	{
		case '+':result=no1+no2;
		printf("Sum= %d",result);
		break;
		case '-':result=no1-no2;
		printf("Difference= %d",result);
		break;
		case '*':result=no1*no2;
		printf("Product= %d",result);
		break;
		case '/':result=no1/no2;
		printf("Quotient= %d",result);
		break;
		case '%':result=no1%no2;
		printf("Remainder= %d",result);
		break;
		default:printf("Invalid choice");
	}
	getch();
}
