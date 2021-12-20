#include<stdio.h>
//book 
struct book
{
	int id;
	char name[20];
	char author[20];
	float price; 
};
typedef struct book book;


void accept( book books[20],int n)
{
	int i;
	for(int i=0;i<n;i++)
	{
		printf("Enter Book Id, Name, Author,price ");
		scanf("%d%s%s%f",&books[i].id,books[i].name,books[i].author,&books[i].price);
	}
}

void write_to_file( book books[20],int n)
{
	int i;
	FILE *fp;
	fp=fopen("books_data.txt","a");//if file is not opened then it will create a file
	
	if(fp==0)
	{
		printf("error");
		return;
	}
	else
	{
		//fputs("book_id\tbook_name\t\tbook_author\\ttbook_price",fp);
		for(i=0;i<n;i++)
		{
			fputs("\n",fp);
			fprintf(fp,"%d\t\t\t%s\t\t\t%s\t\t\t%f",books[i].id,books[i].name,books[i].author,books[i].price);
		}
	}
	fclose(fp);
}

void display ( book  books[20])
{
	FILE *fp; char ch;
	fp=fopen("books_data.txt","r");
    printf("display :\n");
    	if(fp==0)
	{
		printf("error");
		return;
	}
   while ((ch=getc(fp))!=EOF){
      if(ch == ',')
         printf("\t\t");
      else
         printf("%c",ch);
   }
   fclose(fp);
}
void display_particular()
{
	book b;
	FILE *fp;
	int ID;
	fp=fopen("books_data.txt","r");
	printf("Enter book id of book which you want to search :");
	scanf("%d",&ID);
	while(fscanf(fp,"%d%s%s%f",&b.id,b.name,b.author,&b.price)!=EOF)
	{
		if(b.id==ID)
		{
		  printf("Record found :)\n");
	  	  printf("%d\t\t%s\t\t%s\t\t%f\n",b.id,b.name,b.author,b.price);
	  	  return;
	    }
		
	}
	fclose(fp);
	printf("NO record found :( \n"); 
}

void Delete()
{
	book b;
	FILE *fp,*fp2;
	int ID,found=0;
	fp=fopen("books_data.txt","r");
	fp2=fopen("books_data_temp.txt","w");
	printf("Enter book id of book which u want to delete :");
	scanf("%d",&ID);
		if(fp==0 || fp2==0)
	{
		printf("error");
		return;
	}
	while(fscanf(fp,"%d%s%s%f",&b.id,b.name,b.author,&b.price)!=EOF)
	{
		if(b.id==ID)
		{
		  found=1;
      }
	  else
	    fprintf(fp2,"\n%d\t\t\t%s\t\t\t%s\t\t\t%f",b.id,b.name,b.author,b.price);
	
	}
	
	fclose(fp);
	fclose(fp2);
	
	if(found)
	{
	  fp2=fopen("books_data_temp.txt","r");
	  fp=fopen("books_data.txt","w");
	  
	
	    while(fscanf(fp2,"%d%s%s%f",&b.id,b.name,b.author,&b.price)!=EOF)
		{
			fputs("\n",fp);
			fprintf(fp,"%d\t\t\t%s\t\t\t%s\t\t\t%f",b.id,b.name,b.author,b.price);
		}
	  fclose(fp);
	  fclose(fp2);	
	
	}
	else 
	printf("NO record found :( \n");
}

int main()
{
	book books[20];
	int n;
	int choice;
	do{
		printf("\n1.CREATE\n2.DISPLAY\n3.DISPLAY_PARTICULAR\n4.DELETE\n5.EXIT\nenter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:	
			        printf("enter no of books");
			        scanf("%d",&n);
			        accept(books,n);
	                write_to_file( books, n);
				    break;
			case 2:	display(books);
			        break;
			case 3:display_particular();
			       break;
			case 4:Delete();
			         break;
		    case 5: printf("\nTHANK YOU ");
		           return 0;
		    default :
		    	printf("\n WRONG CHOICE !!!");
		    	continue;
		}
	}while(choice!=5);

}