#include<stdio.h>
#include<conio.h>
void main ()
{
	int *p,i,sum=0,a[10];
	float avg;
	clrscr();
	p=a;
	printf("Enter 10 nos.\n");
	for(i=0;i<=9;i++)
	{
		scanf("%d",(p+i));
		sum=sum+*(p+i);
	}
	avg=sum/10.0;
	for(i=0;i<=9;i++)
	printf("%d\n",*(p+i));
	printf("Average=%f",avg);
	getch();
}
