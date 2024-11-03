# include<stdio.h>
# include<conio.h>
void main()
{
	FILE *fp;
	char c=' ';
	clrscr();
	fp=fopen("test.txt","r");
	while(!feof(fp))
	{
		printf("%c",getc(fp));
	}
	fclose(fp);
	fp=fopen("test.txt","a");
	printf("\nWrite data to be stored in the file and once completed press the full stop (.):\n");
	while(c!='.')
	{
		scanf("%c",&c);
		fputc(c,fp);
	}
	fclose(fp);
	fp=fopen("test.txt","r");
	while(!feof(fp))
	{
		printf("%c",getc(fp));
	}
	fclose(fp);
	getch();
}
