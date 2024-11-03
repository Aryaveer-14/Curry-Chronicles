#include<stdio.h>
#include<conio.h>
void main ()
{
	float length, breadth, area, perimeter;
	clrscr();
	printf("Enter the length and breadth of the rectangle:");
	scanf("%f%f",&length,&breadth);
	area= length * breadth;
	perimeter= 2* (length + breadth);
	printf("The area of rectangle is= %f and its perimeter is = %f", area, perimeter);
	getch();
}