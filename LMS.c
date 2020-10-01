#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct Book
{
	char name[20];
	int pages;
	float price;
};

void lining()
{
	int i;
	printf("\n");
	for(i=0; i<80; i++)
		printf("=");
	printf("\n");
}

void show(struct Book b1)
{
	printf("Name of Book\t =\t %s",b1.name);
	printf("\nPages in Book\t =\t %d",b1.pages);
	printf("\nPrice of Book\t =\t %f\n\n",b1.price);
}

void input(struct Book *b1)
{
	float pr;
	fflush(stdin);
	printf("enter the name of book = ");
	gets(b1->name);
	printf("Enter the pages in book = ");
	scanf("%d",&b1->pages);
	printf("Enter the price of the book = ");
	scanf("%f",&pr);
	b1->price=pr;
}

void ADD_RECORD()
{
	FILE *fp;
	struct Book b;
	clrscr();
	printf("....! Adding Records !....\n\n\n");
	fp=fopen("books.txt","a");
	input(&b);
	fwrite(&b,sizeof(b),1,fp);
	fclose(fp);
	printf("\n\nRecord Added successfully !....");
	getch();
}

void SEARCH_RECORD()
{
	int success=0;
	FILE *fp;
	struct Book b;
	char bname[20];
	clrscr();
	fflush(stdin);
	printf("Searching Process .....\n\n");
	printf("Enter the name of book to be searched\n");
	gets(bname);
	fp=fopen("books.txt","r");
	lining();
	while(fread(&b,sizeof(b),1,fp)!=NULL)
	{
		if(strcmpi(b.name,bname)==0)
		{
			success=1;
			show(b);
		}
	}
	lining();
	fclose(fp);
	if(success==0)
		printf("\n\n!SORRY No Record Found");
	getch();
}

void DELETE_RECORD()
{
	FILE *fp;
	FILE *temp;
	struct Book b;
	char bname[20];
	clrscr();
	fflush(stdin);
	printf("Delete Records....\n\n");
	printf("\nEnter the name of book to be deleted\n");
	gets(bname);
	fp=fopen("books.txt","r");
	temp=fopen("temp.txt","w");
	while(fread(&b,sizeof(b),1,fp)!=NULL)
	{
		if(strcmpi(b.name,bname)!=0)
			fwrite(&b,sizeof(b),1,fp);
	}
	fclose(fp);
	fclose(temp);
	remove("books.txt");
	rename("temp.txt","books.txt");
	remove("temp.txt");
	printf("Record Deleted !....");
	getch();
}

void COUNT_RECORD()
{
	int count=0;
	FILE *fp;
	struct Book b;
	clrscr();
	fp=fopen("books.txt","r");
	while(fread(&b,sizeof(b),1,fp)!=NULL)
		count++;
	fclose(fp);
	printf("\nTotal number of records are %d",count);
	getch();
}

void DISPLAY_RECORD()
{
	FILE *fp;
	struct Book b;
	clrscr();
	fp=fopen("books.txt","r");
	lining();
	while(fread(&b,sizeof(b),1,fp)!=NULL)
		show(b);
	lining();
	fclose(fp);
	getch();
}

void main()
{
	int opt;
	while(1)
	{
		clrscr();
		printf("\n\t\t ...:: Institute of Technology and Management ::...");
		printf("\n\n\n\t\t\tWelcome to Library Management System\n\t\t=====================\n\t\t[1] Add Record\n\t\t[2] Count Records\n\t\t[3] Search for Record\n\t\t[4] Display Records\n\t\t[5] Delete Record\n\t\t[6] Exit\n\t\t=================\n\t\t");
		printf("\n\t\tEnter the choice : ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1: ADD_RECORD();  break;
			case 2: COUNT_RECORD();  break;
			case 3: SEARCH_RECORD();  break;
			case 4: DISPLAY_RECORD();  break;
			case 5: DELETE_RECORD();  break;
			case 6: exit(0);  break;
			default: printf("\nWrong Choice Select 1-6");
		}
	}
}



