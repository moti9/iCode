//7) Write a C program to count total number of even and odd elements in an array.
 #include<stdio.h>
 int main(void)
 {int i,ary[10],count_even=0,count_odd=0;
 for(i=0;i<10;i++){
 	printf("Element-%d: ",i);
 	scanf("%d",&ary[i]);    }
 	
 for(i=0;i<10;i++){
 	if(ary[i]%2==0) count_even++;
 	else count_odd++;   }
 	 
 	 printf("\nTotal even Elements in an Array: %d\n",count_even);
 	printf("\nTotal odd Elements in an Array: %d\n",count_odd);
 }
