#include<stdio.h>
#include<conio.h>
void main()
{
	int no1,no2,result,choice;
	clrscr();
     	printf("Enter two numbers:");
	scanf("%d %d",&no1,&no2);
	printf("1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:result=no1+no2;
		printf("Sum= %d",result);
		break;
		case 2:result=no1-no2;
		printf("Difference= %d",result);
		break;
		case 3:result=no1*no2;
		printf("Product= %d",result);
		break;
		case 4:result=no1/no2;
		printf("Quotient= %d",result);
		break;
		case 5:result=no1%no2;
		printf("Remainder= %d",result);
		break;
		default:printf("Invalid choice");
	}
	getch();
}