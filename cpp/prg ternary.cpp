#include<stdio.h>
#include<stdlib.h>
int fact(int x){
	if(x==0 || x==1){return 1;}
	else {return x* fact(x-1);}
	 }
int main()
{
	int n;
	printf("Enter Number:: ");
	scanf("%d",&n);
	printf("\nFactorial of the given number %d ::: %d\n",n,fact(n));
	
	return main();
	
}
