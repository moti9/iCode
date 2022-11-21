#include<stdio.h>
#include<math.h>

int prime_Num(int num){
	int i,flag,p;
	for(int j=2;j<=num;j++ ){
	for(i=2;i<=num/2;i++){
		if(num%i==0){
			p!=num;}
		else {p=num;
		}	
			}}
		for(int j=2;j<=num;j++){
			printf("%d",p);
		}
}

int main(){
	int num,flag,i;
	printf("Enter the range for required prime number = ");
	scanf("%d",&num);
	 
	printf("The prime number in the given range is -\n");
   prime_Num(num);
}
