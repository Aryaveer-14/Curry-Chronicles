#include<stdio.h>
#include<conio.h>
int main()
{
	int i;
	for(i=0;i<8;i++)
	{
		if(i%2==0)
		printf("%d\n",i+1);
		else if(i%3==0)
		continue;
		else if (i%5==0)
		break;
		printf("\n End of Program \n");
	}
	printf("\nEnd of program \n");
}
