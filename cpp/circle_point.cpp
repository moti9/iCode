#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int x,y,x1,y1;
  float r,r1;
  
  printf("Enter centre of the circle(x,y) = ");
  scanf("%d %d",&x,&y);
  printf("Enter the co-ordinate of the point (x1,y1) = ");
  scanf("%d %d",&x1,&y1);
  r=sqrt(pow(x,2) + pow(y,2));
  int a=x-x1;
  int b=y-y1;
  r1=sqrt(pow(a,2) + pow(b,2));
  if(r==r1) printf("The point is on the Circle");
else if(r<r1) printf("The point is outside to the Circle");
else if(r>r1) printf("The point is inside to the Circle");

 return 0;}

