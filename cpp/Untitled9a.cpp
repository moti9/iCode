 //9) Write a program in C to count the frequency of an element of an array. 
 #include<stdio.h>
 int main(void)
 { int i,ary[10],ele,count=0;
 for(i=0;i<10;i++){
 	printf("Element-%d: ",i);
 	scanf("%d",& ary[i]);   }
 	 		
 	printf("\nEnter the element to know the frequency in an Array:");
 	scanf("%d",&ele);
 	
    for(i=0;i<10;i++){
    	if(ary[i]==ele) count++;	}
    	printf("\nThe frequency of the element %d in an Array: %d",ele,count);

 }
