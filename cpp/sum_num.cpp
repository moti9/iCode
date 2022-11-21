#include<stdio.h>
int sum_num(int x,int y){
	int sum=0;
	sum=x+y;
	return sum;
}

int main(){ int a,b;
printf("Enter Num1::");
scanf("%d",&a);
printf("Enter Num2::");
scanf("%d",&b);

printf("Sum of the given number:: %d",sum_num(a,b));

return 0;	
}
