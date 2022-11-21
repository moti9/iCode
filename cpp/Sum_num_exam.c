#include<stdio.h>
#include<math.h>

 int odd_num(int n){
 	int r,num,i=1,j=0;
 	while(n>0){
 	r=n%10;
 	n=n/10;
 	i=n;
	 if(r%2!=0){
 	num=num+ (r*pow(10,j));
	 	j++;
	 }

	num=num*10;	
	 
	 return num;
	  }
	  
int main(){ int n;
 	printf("Enter Number = ");
 	scanf("%d",&n);
 	
 	printf("\n%d",odd_num(n));
 	return 0;}
