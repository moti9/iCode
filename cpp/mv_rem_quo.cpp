#include<stdio.h>
int main(){
	int a,b,rem,quo;
	printf("Enter Num1:: ");
	scanf("%d",&a);
	printf("Enter Num2:: ");
	scanf("%d",&b);
	
	rem=a/b;
	quo=a%b;
	printf("The reminder of %d / %d = %d\n ",a,b,rem);
    printf("The qoutiant of %d / %d = %d ",a,b,quo);
    return 0;
	
}
