#include<stdio.h>
int main(void)
{ int name;
 printf("\n Enter your password: ");
 scanf("%s",& name);
 
 switch(name){
 	case 'N' : printf(" Your Password is correct.");  break;
 	default : printf("  Your password is incorrect, try again.");  break;
 }
     printf("\n*************************************************************\n");	
}
