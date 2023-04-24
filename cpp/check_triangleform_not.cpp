//Write a C program to check whether a triangle can be formed by the given value for the angles.
#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int ang1,ang2,ang3,sum=0;
    
  printf("Enter the Angles of trangle (Angle1,Angle2,Angle3) (Degree)= ");
  scanf("%d %d %d",&ang1,&ang2,&ang3);
  sum=ang1+ang2+ang3;
  if(sum==180) printf("Yes !! it's possible to form Triangle");
  else printf("Opps!! it's not possible to form traingle");

 return 0;}

