#include<stdio.h>
long int fact(int x){ int i,f=1;
if(x==0){ return f;
}
for(i=1;i<=x;i++){
	f=f*i;
	}
	return f;
	}


int main(){
	int n;
	printf("Enter required number:: ");
	scanf("%d",&n);
	printf("Factorial of the given number %d = %ld",n,fact(n));
	
return 0;
}
