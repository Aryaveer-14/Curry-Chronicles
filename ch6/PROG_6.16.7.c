# include<stdio.h>
# include<conio.h>
void main()
{
	FILE *fp;
	int n=0;
	clrscr();
	fp=fopen("test.txt","r");
	while(!feof(fp))
	{
		getc(fp);
		n++;
	}
	n--;
	printf("The total number of characters in the file is %d:\n",n);
	fclose(fp);
	getch();
}
