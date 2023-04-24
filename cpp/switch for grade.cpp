#include<stdio.h>
int main(void)
{ char a;
 printf(" Grade-(E-EXCELLENT, V-VERY GOOD, G-GOOD, A-PASS, B-E CONDITIONAL PASS, F-FAIL)\n ");
 printf(" Type Grade: ");
  scanf("%c",&a); 
 switch(a){
 	case 'F' : printf(" Your grade is FAIL. "); break;
    case 'B' : printf(" Your grade is E-conditional pass. "); break;
    case 'A' : printf(" Your grade is PASS. "); break;
    case 'G' : printf(" Your grade is GOOD. "); break;
    case 'V' : printf(" Your grade is VERY GOOD. "); break;
    case 'E' : printf(" Your grade is EXCELLENT. "); break;
    default : printf(" \n Error ! Invalid Grade. "); break;
 }
  printf("\n******************************************\n"); 	
}
