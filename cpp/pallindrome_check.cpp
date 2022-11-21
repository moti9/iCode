#include<stdio.h>
int main()
{
	int n,r,sum=0,rev;
	printf("Enter required number for checking pallindrome = ");
	scanf("%d",&n);
	rev=n;
	while(n>0){
	r=n%10;
	sum=(sum*10)+r;
	n=n/10;
	}
	
	if(rev==sum){
		printf("The given number is pallindrome.");
	}
	else{
		printf("The given number is not pallindrome.");
	}
	
	return 0;
}
