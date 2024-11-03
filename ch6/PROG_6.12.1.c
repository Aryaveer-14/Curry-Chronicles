#include<conio.h>
#include<stdio.h>
struct circle
{
	float radius;
	struct
	{
		float x,y;
	}centre;
};
void main ()
{
	struct circle c;
	clrscr();
	printf("Enter the radius and x and y co-ordinates of circle:");
	scanf("%f %f %f",&c.radius,&c.centre.x,&c.centre.y);
	printf("Circle Information\nRadius=%f\nCentre co-ordinates:(%f,%f)",c.radius,c.centre.x,c.centre.y);
	getch();
}
