#include<bits/stdc++.h>
using namespace std;
#define ll long int 

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll D,d,p,q,count=0;
        cin>>D>>d>>p>>q;
        ll n=D/d;
        if(n>=2)
        {
        count+=((n/2)*(2*p+(n-1)*q)*d);
        count+=(D%d)*(p+n*q);
        }
        else if(n<2)
        {
            count+=(d*p);
            count+=(D-d)*(p+q);
        }
        cout<<count<<endl;
    }
    return 0;
}
