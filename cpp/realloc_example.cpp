#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

 int main(){
  int* ptr;
  int n;
  //calloc
  	 printf("Enter the size of the required array =");
  	 scanf("%d",&n);
  
  ptr=(int*) calloc(n, sizeof(int));
  for(int i=0;i<n;i++){
  	 printf("Enter the value no %d of this array\n",i);
  	 scanf("%d",&ptr[i]);
  }
for(int i=0;i<n;i++){
  	 printf("The value at %d of this array is %d\n",i,ptr[i]);
  	 
  }
  //realloc
  	 printf("Enter the size of the new required array =");
  	 scanf("%d",&n);
  
  ptr=(int*) realloc(ptr, n*sizeof(int));
  for(int i=0;i<n;i++){
  	 printf("Enter the new value no %d of this array\n",i);
  	 scanf("%d",&ptr[i]);
  }
for(int i=0;i<n;i++){
  	 printf("The new value at %d of this array is %d\n",i,ptr[i]);
  	 
  }
free(ptr);
 return 0;}

