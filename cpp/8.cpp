#include<stdio.h>
int main()
{int n,n1=0,n2=1,i,next;
printf("Fibonacci Series Given Below:\n");
printf("Type No:");
scanf("%d",& n);

for(i=1;i<=n;i++){
	printf("%d   ",n1);
	next=n1+n2;
	n2=n1;
	n1=next;}
	return 0;
}
