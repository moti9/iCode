
#include <iostream>
using namespace std;
void m(int x,int y);
int main() { int a,b;
cin>> a >> b;
    
    cout << "Hello world!"<<'\n';
m(a,b);
    return 0;
}
void m(int x,int y){ int sum;
sum=x + y;
cout<<"sum=" << sum;
    
}
