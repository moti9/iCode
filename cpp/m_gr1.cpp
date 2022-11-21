#include<stdio.h>
#include<math.h>

int main()
{int n;
scanf("%d",&n);
int a=1,b=2,c;
for(int i=1;i<=n;i++){
	 
   printf("%d",a);
   c=a+b;
   a=b;
   b=c;
   if(a==21) break;
   printf("+");

}



return 0;}

