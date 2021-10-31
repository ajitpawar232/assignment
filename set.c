#include<stdio.h>
#define size 5 


void accept(int *p){
for (int i = 0; i < size; i++)
{
   printf("Enter the element %d:\n",i+1);
   scanf("%d",&p[i]);
}}



void display(int *p,int n){
   printf("The set is:");
printf("{");
for (int i = 0; i < n; i++)
{  
   printf("\t%d",p[i]);
}
printf("}\n");
}



int union_function(int arr1[],int arr2[],int union_set[]){
   int i,j,k=0;
   for ( i = 0; i < size; i++)
   {
      union_set[k]=arr1[i];
      k++;
   }
   for ( i = 0; i < size; i++)
   {
     
      for (j = 0; j < size ; j++)
      {
         if (arr2[i]==arr1[j])
         {
            break;
         } 

      }
      if (j==size)
      {
         union_set[k]=arr2[i];
         k++;
      }
      
   }printf("The Union set is:");
         printf("{");
         for (int i = 0; i < k; i++)
         {
            printf("\t%d",union_set[i]);
         }
         printf("}\n");
   
}



int intersection_function(int arr1[],int arr2[],int inter_set[])
{
   int i,j,k=0;
  for ( i = 0; i < size; i++)
   {
     
      for (j = 0; j < size ; j++)
      {
         if (arr2[i]==arr1[j]){
            inter_set[k]=arr2[i];
            k++;

         }
      }
   }  printf("The Intersection set is:");
         printf("{");
         for (int i = 0; i < k; i++)
         {
            printf("\t%d",inter_set[i]);
         }
         printf("}\n");
        
}





 int difference_function1(int arr1[],int arr2[],int difference1[]){
    int i,j,k=0,l=0;
     for(int i=0;i<size;i++)
    {
      
        for(j=0;j<size;j++)
        {
            if(arr2[j]==arr1[i])
             break;
        }
        if(j==size)
        {
            
            for(l=0;l<k;l++){
         
                if(difference1[l]==arr1[i])
                 break;
            }
            if(l==k)
            {
                difference1[k]=arr1[i];
                k++;
            }
        }
        
    }
    printf("The A-B set is:");
         printf("{");
         for (int i = 0; i < k; i++)
         {
            printf("\t%d",difference1[i]);
         }
         printf("}\n");

}



 int difference_function2(int arr1[],int arr2[],int difference2[]){
    int i,j,m=0,l=0;
       for( i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(arr2[i]==arr1[j])
             break;
        }
        if(j==size)
        {
            for(l=0;l<m;l++)
            {
                if(difference2[l]==arr2[i])
                 break;
            }
            if(l==m)
            {
                difference2[m]=arr2[i];
                m++;
            }
        }
        
    }
    printf("The B-A set is:");
         printf("{");
         for (int i = 0; i < m; i++)
         {
            printf("\t%d",difference2[i]);
         }
         printf("}\n");

}



int syymetric_difference(int arr1[],int arr2[],int syy_difference[]){
    int i,j,m=0,l=0,k=0,n=0;
    int difference2[size];
    int difference1[size];
       for( i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(arr2[i]==arr1[j])
             break;
        }
        if(j==size)
        {
            for(l=0;l<m;l++)
            {
                if(difference2[l]==arr2[i])
                 break;
            }
            if(l==m)
            {
                difference2[m]=arr2[i];
                m++;
            }
        }
        
    }
    
     for(int i=0;i<size;i++)
    {
      
        for(j=0;j<size;j++)
        {
            if(arr2[j]==arr1[i])
             break;
        }
        if(j==size)
        {
            
            for(l=0;l<k;l++){
         
                if(difference1[l]==arr1[i])
                 break;
            }
            if(l==k)
            {
                difference1[k]=arr1[i];
                k++;
            }
        }
        
    }
     for(i=0;i<k;i++)
    {
        syy_difference[n]=difference1[i];
        n++;
    }
    for(i=0;i<m;i++)
    {
        syy_difference[n]=difference2[i];
        n++;
    }
    printf("The Syymetric set is:");
         printf("{");
         for (int i = 0; i < n; i++)
         {
            printf("\t%d",syy_difference[i]);
         }
         printf("}\n");   

}



int main()
{

   int arr1[size],arr2[size],union_set[size*2],inter_set[size],difference1[size],difference2[size],syy_difference[size];
   int l,m,n;
   int operator,ch;
   printf("Enter your 1st array\n");
   accept(arr1);
   display(arr1,size);
   printf("Enter your 2nd array\n");
   accept(arr2);
   display(arr2,size);
   table:
   printf("\n********************MENU********************\n");
   printf("\t1. Union\n\t2. Intersection\n\t3. Difference(A-B)\n\t4. Difference(B-A)\n\t5. Symmertric Difference\n");
   printf("Enter what you want to do: ");
   scanf("\n%d",&operator);
   switch(operator)
{
 
  case 1:  printf("The Union of sets\n");
   union_function(arr1,arr2,union_set);
    break;

  case 2: printf("The Intersection of sets\n");
   intersection_function(arr1,arr2,inter_set);
    break;

  case 3: printf("The Difference (A-B)\n");
   difference_function1(arr1,arr2,difference1);
    break;

  case 4: printf("The Difference (B-A)\n");
   difference_function2(arr1,arr2,difference2);
    break;

  case 5: printf("The Symmetric Difference of sets\n");
   syymetric_difference(arr1,arr2,syy_difference);
    break; 

  default:
        printf("Invalid Input\n");
        break;


}
printf(" \n Enter 1 for Continue or 0 to Break :");
scanf("%d",&ch);
if(ch==1){
        goto table;
  }
  else{
    return 0;
  }


}

