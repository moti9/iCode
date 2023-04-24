#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int x1,y1,x2,y2,x3,y3;
  float d1,d2,d3;
  printf("Enter the co-ordinate of point (x1,y1) = ");
  scanf("%d %d",&x1,&y1);
  printf("Enter the co-ordinate of the point (x2,y2) = ");
  scanf("%d %d",&x2,&y2);
  printf("Enter the co-ordinate of the point (x3,y3) = ");
  scanf("%d %d",&x3,&y3);
  int a=x1-x2,b=x2-x3,c=x3-x1;
  int x=y1-y2,y=y2-y3,z=y3-y1;
  
  d1=sqrt(pow(a,2) + pow(x,2));
  d2=sqrt(pow(b,2) + pow(y,2));
  d3=sqrt(pow(c,2) + pow(z,2));
  if(d1==d2+d3 || d2==d1+d3 || d3==d1+d2) printf("The points are on the straight line");
else  printf("The points are not on the straight line");


 return 0;}

