#include <iostream>

using namespace std;

unsigned long long factorial(int n)
{
	const unsigned int M = 1000000007;

	unsigned long long f = 1;
	for (int i = 1; i <= n; i++)
		f = (f*i) % M; 
						
	return f;
}
 
int main() {
	int n;
	cin>>n;
	   while(n--){
	   	int a;
	   	cin>>a;
	   	cout<<factorial(a)<<endl;
	   }
	return 0;
}

