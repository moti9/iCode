//Write a C program to check whether a triangle is Equilateral, Isosceles or Scalene.
#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int a,b,c;
  printf("Enter the sides of triangle(a,b,c) = ");
  scanf("%d %d %d",&a,&b,&c);
  if(a==b && b==c) printf("This is an equilateral triangle");
  else if(a==b || b==c || c==a) printf("This is an isoscele triangle");
  else printf("This is a scalene triangle"); 

 return 0;}

