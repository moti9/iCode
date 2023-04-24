#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int x,y;
   printf("Enter the co-ordinate of the point (x,y) = ");
  scanf("%d %d",&x,&y);
if(x==0 && y==0)  printf("Entered point lying on centre ");
 else if(x!=0 && y==0)  printf("Entered point lying on X-axis ");
 else if(x==0 && y!=0)  printf("Entered point lying on Y-axis ");
 else printf("Entered point not lying on X-axis and Y-axis");
 return 0;}

