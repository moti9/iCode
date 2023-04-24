#include<stdio.h>
int main(void){
double sum;
{ int n;
printf("Type value of n:");
scanf("%d",& n);
double i, s = 0.0; 
for (i = 1; i <= n; i++) 
	s = s + 1/i; 
sum=sum+s;
} 

	printf("Sum is %lf", sum); 


}
