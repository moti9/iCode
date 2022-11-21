//Write a C program to find whether a given year is a leap year or not.
#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int yr;
  printf("Enter required year for check leap yr or not = ");
  scanf("%d",&yr);
  if((yr%4==0 && yr%100!=0) || yr%400==0) printf("Entered year is a leap year");
  else printf("This is not a leap year");

 return 0;}

