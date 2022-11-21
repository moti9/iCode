#include<stdio.h>
#include<math.h>
long int cube(int x){
	return pow(x,3);
}
int main(void){
	int n;
	printf("Enter required number = ");
	scanf("%d",&n);
	printf("The cube of the given number = %ld",cube(n));
}
