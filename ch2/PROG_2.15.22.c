#include<stdio.h>
#include<conio.h>
void main ()
{
	int a=2,b=3,ab=4;
	int i;
	int in='2'*2;
	char ch='c';
	clrscr();
	printf("%c %c\n",ch,(++ch));
	printf("%d %d %d\n",a,a,++a);
	printf("%d %d %d\n",b,b,++b);
	printf("%d %d %d\n",ab,ab,++ab);
	printf("%d %d\n",a,!!a);
	getch();
}
