#include<stdio.h>
int check_num(int x){
	if(x%2==0){
		printf("The given number is EVEN.");
	}
	else{ printf("The given number is ODD.");
	}
}

int main(){
	int n;
	printf("Enter the required number for checking ODD or EVEN = ");
	scanf("%d",&n);
	check_num(n);
	printf("\n");
	return main();
}
