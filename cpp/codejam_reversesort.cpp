#include<stdio.h>
int reverse(int a, int b){
	int temp;
	temp=x;
	x=y;
	y=temp;
	return x,y;
}
int main(){
	int t,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		int arr[n];
		for(int j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		int result=0;
		for(int j=0;j<n-1;j++){
			int min=128,index=-1;
			for(int k=j;k<n;k++){
				if(arr[k]<min){
					min=arr[k];
					index=k;
				}
			}
			reverse(arr+j,arr+index+1);
			result+=(index-j)+1;
		}
		printf("Case #%d: %d",i+1,result);
	}
return 0;	
}
