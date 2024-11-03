#include<conio.h>
#include<stdio.h>
struct cricketer
{
	char name[20], country[20];
	int best;
	float avg;
};
void main ()
{
	struct cricketer c1[25],temp;
     	int i,j;
	float dummy;
	clrscr();
	for(i=0;i<=24;i++)
	{
		printf("Enter the cricketer's name, country, best score and average runs scored:");
		scanf("%s %s %d %f",c1[i].name,c1[i].country,&c1[i].best,&dummy);
		c1[i].avg=dummy;
	}
	for(i=0;i<=24;i++)
	{
		for(j=0;j<=23;j++)
		{
			if(c1[j].avg<c1[j+1].avg)
			{
				temp=c1[j];
				c1[j]=c1[j+1];
				c1[j+1]=temp;
			}
		}
	}
	for(i=0;i<=24;i++)
	printf("%s\t%s\t%d\t%f\n",c1[i].name,c1[i].country,c1[i].best,c1[i].avg);
	getch();
}
