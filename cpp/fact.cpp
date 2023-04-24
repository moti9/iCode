#include<iostream>
using namespace std;
#define ll long long
int fact(int n) {
	if(n==0) return 1;
	else return n*fact(n-1);
}
void solve() {
	//Write your code here
	int n;
	cin>>n;
	cout<<fact(n)<<"\n";
}
int main() {
	ll tt=1;
	//cin>>tt;
	while(tt--) {
		solve();
	}
	return 0;
}
