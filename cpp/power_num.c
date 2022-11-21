#include<stdio.h>
#include<math.h>
#define ll long long int
ll power(int a, int b){
	ll f=1; 
	while(b--){
		 f=f*a;
	}
	return f;
}
int main()
{ int value,po;
  scanf("%d %d",&value,&po);
  ll x=power(value,po);
  printf("%lld",x);


return 0;}

