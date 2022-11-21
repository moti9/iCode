#include<stdio.h>
 int main(){
  int x;
  scanf("%d",&x);
  if((x & (x-1))==0){
  	printf("Yes it contain 2 power");
  }
  else{ printf("No contain 2 power");
  }

 return 0;}

