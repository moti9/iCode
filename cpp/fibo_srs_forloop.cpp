#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

 int main(){ int n,n1=0,n2=1,next;
 printf("Enter number for printing fibo..series ..= ");
 scanf("%d",&n);
 printf("Fibona..Series is.....\n");
 for(int i=1;i<=n;i++){
 	printf("%d\t",n1);
 	next=n1+n2;
 	n2=n1;
 	n1=next;
 }
printf("\n\n.....**************************......\n ");
 
 return 0;}

