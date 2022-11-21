#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int arr[n];
		for(int j=0;j<n;j++){
			cin>>arr[j];
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
		cout<<"Case #"<<i+1<<": "<<result<<endl;
	}
}
