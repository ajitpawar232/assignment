#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;

struct cricket
{
    char name[20],country[20],category[20];
    int age,wickets,no_odi,no_it20;
    float bat_avg;
};
typedef struct cricket crick;

void input	(crick *c)
  {
   printf("\nEnter the data for player\n ");
   for (int i = 0; i < n; i++)
  {
     printf("\nEnter the name of player %d: ",i+1);
     scanf("%s", c[i].name);
     printf("\nEnter age: ");
     scanf("%d",&c[i].age);
     printf("\nEnter country: ");
     scanf("%s",c[i].country);
     printf("\nEnter category of player [batsman,bowler,wicket_keeper,all_rounder]: ");
     scanf("%s",c[i].category);
     printf("\nEnter number of ODIs played: ");
     scanf("%d",&c[i].no_odi);
     printf("\nEnter number of T20 played: ");
     scanf("%d",&c[i].no_it20);
     printf("\nEnter average batting score: "); 
     scanf("%f",&c[i].bat_avg);
     printf("\nEnter total numbers of wickets taken: ");
     scanf("%d",&c[i].wickets);

  }
  }



void display(crick c[])
	{
	 	
       int k,j;crick temp;
       for(k=1;k<n;k++)
       {
          j=k-1;
          temp=c[k];
          while(j>-1 && c[j].bat_avg>temp.bat_avg)
          {
            c[j+1]=c[j];
            j--;
          }
          c[j+1]=temp;

       }
		printf("\nName\tAge\tCountry\tCategory\tODI\tT_20\tAvg_batting score\tWicket");
		for(int j=0;j<n;j++)
		{
			printf("\n%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t\t%d",c[j].name,c[j].age,c[j].country,c[j].category,c[j].no_odi,c[j].no_it20,c[j].bat_avg,c[j].wickets);
		}

     }


void num_batsman(crick c[])
	 {
	 	
	 	char cntry[20];
	 	int count=0,n,m;
	 	printf("\nEnter name of country: ");
	 	scanf("%s",cntry);
	 	for(int j=0;j<n;j++)
	 	{
	 	   n=	strcmp(cntry,c[j].country);
	 	   m= strcmp("batsman",c[j].category);
	 	   if(n==0 && m==0)
	 	    count++;
		 }
    	 printf("\n%d batsman are there of  country %s",count+1,cntry);
	 } 

void  high_avg_score(crick c[])
  {
	int j;int loc=0;
	float max=c[0].bat_avg;
	  for( j=1;j<n;j++)
	 {
		if(max<c[j].bat_avg){
		    max=c[j].bat_avg;
        loc=j;}
	 }
	
   printf("\nName\tAge\tCountry\tCategory\tODI\tT_20\tAvg_batting score\tWicket");
	 	   	  printf("\n%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t\t%d",c[loc].name,c[loc].age,c[loc].country,c[loc].category,c[loc].no_odi,c[loc].no_it20,c[loc].bat_avg,c[loc].wickets);
  }


void num_bowler( crick c[])
	 {
	 	
	 	char cntry[20];
	 	int count=0,n,m;
	 	printf("\nEnter name of country: ");
	 	scanf("%s",cntry);
	 	   for(int j=0;j<n;j++)
	 	 {
	 	   n=	strcmp(cntry,c[j].country);
	 	   m= strcmp("bowler",c[j].category);
	 	   if(n==0 && m==0)
	 	    count++;
		  }
		 printf("\n%d bowlers are there of  country %s",count,cntry);
	 }


void  max_wicket(crick c[])
{
	int j;int loc1=0;
	float max=c[0].wickets;
	  for( j=0;j<n;j++)
	 {
		if(max<c[j].wickets){
		    max=c[j].wickets;
        loc1=j;}
	 }

   printf("\nName\tAge\tCountry\tCategory\tODI\tT_20\tAvg_batting score\tWicket");
	 	   	  printf("\n%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t\t%d",c[loc1].name,c[loc1].age,c[loc1].country,c[loc1].category,c[loc1].no_odi,c[loc1].no_it20,c[loc1].bat_avg,c[loc1].wickets);
}	 



void particular_player(crick c[])
{
   	    char Name[20];
	 	int count=0,i;
	 	printf("\nEnter name of player to display his full information: ");
	 	scanf("%s",Name);
	 	 for(int j=0;j<n;j++)
	 	{
	 	   i=	strcmp(Name,c[j].name);
	 	   if(i==0)
			{
	 	   	  printf("\nName\tAge\tCountry\tCategory\tODI\tT_20\tAvg_batting score\tWicket");
	 	   	  printf("\n%s\t%d\t%s\t%s\t\t%d\t%d\t%f\t\t%d",c[j].name,c[j].age,c[j].country,c[j].category,c[j].no_odi,c[j].no_it20,c[j].bat_avg,c[j].wickets);
	 	   	  return ;
			}
	 	    
		 }
		
}

int main()
{
    int choice,ch;
    printf("Enter the number of players: ");
    scanf("%d",&n);
    crick *c=(crick*) malloc(n*sizeof(crick));
    
    table:
    printf("\n\n*************MENU*************\n");
    printf("\nEnter 1 to give Inputs");
    printf("\nEnter 2 to sort the batsman as per the average batting score");
    printf("\nEnter 3 to display number of batsman of particular country");
    printf("\nEnter 4 to batsman with highest average batting score");
    printf("\nEnter 5 to numbers of bowlers of a particular country");
    printf("\nEnter 6 to the bowler that has taken a maximum number of wickets");
    printf("\nEnter 7 to show particular players entire display board information");
    printf("\nEnter 8 to Exit");

    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    if (choice>8 || choice<1)
    {
        printf("\n\n!!!!!! You have entered the wrong choice !!!!!!");
        goto table;

    }

    switch(choice)
		{
			case 1: input (c);
			        break;
			case 2: display(c);
				     break;
			case 3: num_batsman(c);
				     break;
			case 4: high_avg_score(c);
				     break;
			case 5: num_bowler(c);
				     break;
			case 6: max_wicket(c);
				     break;
			case 7: particular_player(c);
				     break;
			case 8: printf("Thank You !!!!");
				     return 0;
		}

    printf("\n\nEnter 1 for Continue or 0 to Break: ");
scanf("%d",&ch);
if(ch==1){
        goto table;
  }
  else{
    return 0;
  }


}
