//Write a C program to check whether a character is an alphabet, digit or special character.
#include<stdio.h>
#include<math.h>
#include<string.h>

 int main(){
  char ch;
  printf("Enter the required character for check = ");
  scanf("%c",&ch);
  
  if(ch>='a' && ch<='z' || ch>='A' && ch<='Z') printf("Your entered character is an Alphabet");
else if(ch>='0' && ch<='9') printf("Your entered character is a Digit");
else printf("Your entered character is a special character");
 return 0;}

