#include<stdio.h>
#include<math.h>

 int odd_num(int n){
 	int r,i=1,j=0,num;
 	while(i>=1){
 	r=n%10;
 	n=n/10;
 	i=n;
	 if(r%2!=0){
 	num=num+ r*pow(10,j);
	 	j++;
	 }}

	num=num*10;	
	 
	 return num;
	  }
	  
int main()
{ int n,m;
 	printf("Enter Number = ");
 	scanf("%d",&n);
 	m=odd_num(n);
 	
 	printf("%d",m);
 	
 	return 0;}
