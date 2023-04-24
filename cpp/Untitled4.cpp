#include<stdio.h>
int main()

{ int i,sum=0;

for(i=1;i<=30;){ 
if(i%2==0){ printf("%d\t",i);}
else { continue;}
}

sum+=i;
i++;

printf("Sum of 15 even nos:%d",sum);
return 0;
	
}
