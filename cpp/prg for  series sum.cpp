#include<stdio.h>
 
int main(void) {
   int i, j,k=1;
 
   for (i =1; i <= 4; i++) {
      printf("\n");
      for (j = 1; j <= i; j++) {
         printf("\t%d ",k);
         k++;
      }printf("\n");
   }
   
}
