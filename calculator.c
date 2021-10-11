#include<stdio.h>
int main()
{
float l,m,n;
char operator;
int a;
table:
printf("\n enter the operator (-,+,/,*)");

scanf("%c",&operator);printf("\n enter the two numbers");
scanf("%f%f",&l,&m);

switch(operator)
{
 
  case'+': n=l+m;
    printf(" \n addition is %f",n);
    break;

  case'-': n=l-m;
    printf(" \n substraction is %f",n);
    break;

  case'*': n=l*m;
    printf(" \n multiplication is %f",n);
    break;

  case'/': n=l/m;
    printf(" \n division is %f",n);
    break;

  default:
        printf("Invalid Input\n");
        break;


}
printf(" \n enter 1 for continue or 0 to break :");
scanf("%d",&a);{
  if(a==1){
        goto table;
  }
  else{
    return 0;
  }
}
}