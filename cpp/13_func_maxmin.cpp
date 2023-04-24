#include<stdio.h>
int max_min(int x,int y) {
	if(x>y)  {
		printf("Maximum Number = %d\n Minimum Number = %d \n",x,y);
	} else if(x<y) {
		printf("Maximum Number = %d \n Minimum Number = %d\n",y,x);
	} else  {
		printf("The given numbers are equal.");
	}
}
int main() {
	int a,b;
	printf("Enter Num1 = ");
	scanf("%d",&a);
	printf("Enter Num2 = ");
	scanf("%d",&b);
	max_min(a,b);
	return 0;
}
