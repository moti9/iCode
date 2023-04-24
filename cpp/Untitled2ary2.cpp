//2) Write a program in C to read n number of values in an array and display it in reverse order.
 
 
 #include<stdio.h>
 int main(void)
 {
 	int i,ary[10];
 	printf("Enter Array:\n");
 	for(i=0;i<10;i++){ printf("Element-%d: ",i);
 	scanf("%d",& ary[i]);	 }
 	printf("\nAfter reverse of Array: ");
 	for(i=9;i>=0;i--){ printf("%d[%d]\t",i,ary[i]);}
 	
printf("\n\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
 }
