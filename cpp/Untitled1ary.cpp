//1) Write a program in C to store elements in an array and print it.
 
 
 #include<stdio.h>
 int main(void)
 { int i,ary[10];
 printf("Type 10 elements in Array: \n");
 for(i=0;i<10;i++){
 printf("Element - %d: ",i);
 scanf("%d",& ary[i]);}
 printf("\n Array orders are Like: \n");
 for(i=0;i<10;i++){
 	printf("%d[%d]\n",i,ary[i]);
 }
 printf("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
 	
 }
