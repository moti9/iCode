#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

 int main(){
  int div,sub_num;
  printf("Enter division(class )[1st=1::2nd=2::3rd=3] of student = ");
  scanf("%d",&div);
  printf("Enter number of failed subject = ");
  scanf("%d",&sub_num);
  switch(div){
   case 1 : if(sub_num>3){ printf("The awarded grace marks is 0.");}
            else { printf("The awarded grace marks is 5.");			}
	break;
	
	case 2 : if(sub_num>2){ printf("The awarded grace marks is 0.");}
            else { printf("The awarded grace marks is 4.");			}
	break;
	
	case 3 : if(sub_num>1){ printf("The awarded grace marks is 0.");}
            else { printf("The awarded grace marks is 5.");			}
	break;
	
	default : printf("Invalid input !! Please enter valid input b/w 1-3.");
	
	}
  

 return 0;}

