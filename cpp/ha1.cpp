#include<stdio.h>
int sum(int x){ int i,sum=0;
for(i=x;i>=1;i--)
	{if(i%2==0){ sum+=i;}
	else { sum-=i;}}
return sum;	
}
int main(){ int n;
printf(">>Num =");
scanf("%d",&n);
printf("sum= %d\n",sum(n));

return main();
}
