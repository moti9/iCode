#include<stdio.h>
int main()
{ int a, b, c, d, e, f;
 
 printf("Enter value of a:");
 scanf("%d",& a);
 
 printf("Enter value of b:");
 scanf("%d", & b);
 //Calculating
 c=a+b;
 d=a-b;
 e=a*b;
 f=a/b;
 
 printf("Sum of given number is: %d", c);
 printf("Difference of given number is: %d", d);
 printf("Product of given number is:%d", e);
 printf("Dividion of given number is: %d", f);
 
 return 0;
 
}
