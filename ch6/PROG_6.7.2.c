#include<stdio.h>
#include<conio.h>
void incr()
{
	static int i=0;
	i++;
	printf("%d\n",i);
}
int main()
{
	incr();
	incr();
	incr();
	getch();
}
