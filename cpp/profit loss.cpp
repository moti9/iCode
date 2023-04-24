#include<stdio.h>
int main(){
	int a,b,amount;
	
	printf("Type cost price = ");
	scanf("%d",&a);
	
	printf("Type selling = ");
	scanf("%d",&b);
if (b>a){ amount=b-a;
printf("\nProfit Amount = %d ",amount);}	
 else if(b<a){
 	amount=a-b;
 	printf("\nLoss amount = %d ",amount);}
 else {
 	printf("\nNo Profit No Loss"); }	
 	
 	return 0;
}
