//Write a C program to read the age of a candidate and determine whether it is eligible for casting his/her own vote.
#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  int age;
  printf("Enter age of the candidate = ");
  scanf("%d",&age);
  if(age<18) printf("You are not eligible for vote");
  else printf("You are eligible for vote");

 return 0;}

