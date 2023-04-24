#include<stdio.h>
#include<math.h>
int num_digit(int n){
	int ct=0;
	while(n!=0){
		n/=10;
		ct++;
	}
	return ct;
}
int main()
{ int no;
   scanf("%d",&no);
   
   printf("%d",num_digit(no));


return 0;}

