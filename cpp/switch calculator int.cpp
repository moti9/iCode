#include<stdio.h>
int main(void)
{ int choice; 
double a,b;

printf("\n '1 for Add(+)' '2 for Sub(-)' '3 for Mult' '4 for Div' \n");
printf("\nEnter Choice: ");
scanf("%d", & choice);
 printf("Type No1: ");
    scanf("%lf", &a);
    printf("Type No2: ");
    scanf("%lf", &b);
    
    switch(choice){
    	case 1 :  printf("Calculation: %lf + %lf = %lf\n",a,b,a+b); break;
    	case 2 : printf("Calculation: %lf - %lf = %lf\n",a,b,a-b); break;
        case 3 : printf("Calculation: %lf * %lf = %lf\n",a,b,a*b); break;
        case 4 : printf("Calculation: %lf / %lf = %lf\n",a,b,a/b); break;}
            
printf("\n***********************************************\n");
}
