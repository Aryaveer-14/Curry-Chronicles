# include<stdio.h>
# include<conio.h>
void main()
{
	FILE *fp,*fp1;
	char c;
	clrscr();
	fp=fopen("test.txt","r");
	fp1=fopen("test1.txt","w");
	while(!feof(fp))
	{
		c=getc(fp);
		fputc(c,fp1);
	}
	fclose(fp1);
	fclose(fp);
	fp1=fopen("test1.txt","r");
	printf("Displaying data from the new file:\n");
	while(!feof(fp1))
	{
		printf("%c",getc(fp1));
	}
	fclose(fp1);
	getch();
}
