#include<stdio.h>
#include<conio.h>
void main ()
{
	float km, mt, inch, ft, cm;
	clrscr();
	printf("Enter the distance between two cities in kilometers:");
	scanf("%f",&km);
	mt =km*1000;
	ft = mt * 3.33;
	cm = mt * 100;
	inch = ft *12;
	printf("The distance is= %f mts = %f ft = %f  cm = %f inches.", mt, ft, cm, inch);
	getch();
}
