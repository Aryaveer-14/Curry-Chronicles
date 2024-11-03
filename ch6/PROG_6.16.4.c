# include<stdio.h>
# include<conio.h>
void main()
{
	FILE *fp;
	char name[20],temp1[20];
	int roll,temp2;
	clrscr();
	fp=fopen("Student.txt","w+");
	printf("Enter name and roll number of the student:");
	scanf("%s %d",name,&roll);
	fprintf(fp,"%s %d",name,roll);
	printf("Name\tRoll no.\n");
	rewind(fp);
	fscanf(fp,"%s %d",temp1,&temp2);
	printf("%s\t%d",temp1,temp2);
	fclose(fp);
	getch();
}
