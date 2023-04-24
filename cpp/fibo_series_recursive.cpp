#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
int fibo_rec(int n){

	if (n==1) return 0;
	else if (n==2 || n==3 )
		 return 1;
		else
			 return fibo_rec(n-1) + fibo_rec(n-2);
			
			 
}
 int main(){ int n;
 printf("Enter number for printing fibo..series ..= ");
 scanf("%d",&n);
 printf("\nFibonacci Series is..........\n");
 for(int i=1;i<=n;i++){ 
				printf("%d\t",fibo_rec(i));
			}


 return 0;}

