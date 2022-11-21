 //4) Write a program in C to find the sum of all elements of the array.
 #include<stdio.h>
 int main(void)
 { int i,sum=0,ary[5];
 
 for(i=0;i<5;i++){ printf("Element -%d :",i);
 scanf("%d",& ary[i]); }
 
 for(i=0;i<5;i++){ sum +=ary[i]; }
 printf("\nSum of all elements of the Array: %d\n",sum);
 printf("\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
 }
