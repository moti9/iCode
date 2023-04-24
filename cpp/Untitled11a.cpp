//11) Write a program in C to sort elements of the array in descending order. 
  #include<stdio.h>
 int main(void)
 { int i,j,a,ary[10];
 for(i=0;i<10;i++){
 	printf("Element-%d: ",i);
 	scanf("%d",& ary[i]);   }
 	 		
 	printf("\nAfter the sorting of elements the Array will be: ");
 	
    for(i=0;i<10;i++){ 
    for(j=i+1;j<10;j++){ if(ary[i]<ary[j]){
    a=ary[i];
	ary[i]=ary[j];
	ary[j]=a;  	}  	}     }
	
	for(i=0;i<10;i++)
    	printf("\n%d[%d]",i,ary[i]);

 }
