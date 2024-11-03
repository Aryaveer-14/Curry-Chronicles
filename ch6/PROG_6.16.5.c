# include<stdio.h>
# include<conio.h>
void main()
{
	FILE *fp;
	char name[20];
	int roll,choice=0;
	clrscr();
	while(choice!=3)
	{
		printf("1.New Entry\n2.Display all entries\n3.Exit\nEnter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	fp=fopen("Student.txt","a");
				printf("Enter name and roll number of the student:");
				scanf("%s %d",name,&roll);
				fprintf(fp,"%s %d",name,roll);
				fclose(fp);
				break;
			case 2:	fp=fopen("Student.txt","r");
				printf("Name\tRoll no.\n");
				while(!feof(fp))
				{
					fscanf(fp,"%s %d",name,&roll);
					printf("%s\t%d\n",name,roll);
				}
				fclose(fp);
				break;
			case 3: break;
			default: printf("Invalid Choice\n");
		}
	}	
		getch();
}
