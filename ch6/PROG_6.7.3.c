#include<stdio.h>
#include<conio.h>
int a=5;
void main()
{
	int a=10;
	printf("%d\n",a);
	printf("%d\n",::a);
	a=::a+a;
	printf("%d\n",a);
	printf("%d\n",::a);
	::a=a;
	printf("%d\n",a);
	printf("%d\n",::a);
	getch();
}
