#include<stdio.h>

void main()
{
	int i,j,n,k,l,p;
 printf(" enter the number of rows");
 scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
	    for(p=1;p<=45;p++)
		{
			printf(" ");
			}
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
			}
		for(k=1;k<=i;k++)
		{

			printf("* ");
		}

	printf("\n");
	}
//--------------------------------------
for(i=1;i<=n-1;i++)
	{
	    for(p=1;p<=45;p++)
		{
			printf(" ");
			}
		for(j=1;j<=i;j++)
		{
			printf(" ");
			}
		for(k=1;k<=n-i;k++)
		{

			printf("* ");
		}

	printf("\n");
	}
}
