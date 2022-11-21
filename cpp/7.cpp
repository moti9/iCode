#include<stdio.h>
int main()
{//getting between 10 & 99
	int l=10,h=99,i,num,rem;

printf("Palindrome no between %d & %d:",l,h);
for(i=l;i<=h;i++){ rem=i%10;
num=i/10;

if(rem==num){printf("%d\t",i);}
}
 
 return 0;	
}
