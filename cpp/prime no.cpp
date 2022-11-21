#include<stdio.h>
int main(){
	int n,i,prime,flag=0;
	printf("Enter range of the prime number = ");
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(i%1==0 && i%i==0){
			flag=1;
			}
			else{ continue;
			}
	}
	printf("The prime number in the given range is..\n");
	if(flag=1){
	printf("%d\t",prime);}
	return 0;
}
