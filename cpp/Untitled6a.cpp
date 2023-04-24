//6) Write a program in C to find all even numbers in an array.
#include<stdio.h>
 int main(void)
 { int i,ary[10];
 for(i=0;i<10;i++){ 
 printf("Type num%d: ",i+1);
 scanf("%d",&ary[i]); }

 printf("\nAll even numbers in an Array are the following:\n");
 for(i=0;i<10;i++){
 	if(ary[i]%2==0) printf("%d\t",ary[i]);
 	else continue; }
 }
