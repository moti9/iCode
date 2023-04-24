#include<stdio.h>
int main(){
	int A,B,i;
	printf("Enter required two number = ");
	scanf("%d %d",&A,&B);
	
	printf("\n A is divisible by B...list of number\n");
	for(i=1;i<=B;i++){
		if(A%i==0){
			printf("%d\t",i);
		}
		else {
			continue;
		}
	}
return 0;	
}
