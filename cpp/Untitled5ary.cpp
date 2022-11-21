//5) Write a program in C to find a specific element in an array.
#include<stdio.h>
int main(void)
{ int i,ary[10],spn,match=0;

for(i=0;i<10;i++){ printf("Element-%d: ",i);
scanf("%d",& ary[i]); }
printf("\nEnter specific element: ");
scanf("%d",& spn);

for(i=0;i<10;i++){ if(ary[i]==spn) {
match=1;
break;}}

if(match==1)
 printf("\nThe specific element %d in an Array with position %d",spn,i+1);
else 
printf("\n...The specific element %d is not in an Array....",spn);
	
}
