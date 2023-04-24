#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define endl "\n"
using namespace std;

ll op(ll a, ll b, char ch)
{
    switch (ch)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}

int main()
{
    vector<string> v = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    stack<ll> st;
    ll n1, n2;
    for (auto a : v)
    {
        //   for(auto b:a){
        if (a == "+" || a == "-" || a == "*" || a == "/")
        {
            n1 = (ll)st.top();
            st.pop();
            n2 = (ll)st.top();
            st.pop();
            char ch = a[0];
            ll temp = op(n2, n1, ch);
            // cout << temp << endl;
            st.push(temp);
        }
        else
            st.push((ll)(stoi(a)));
        //   }
    }
    cout << st.top() << endl;
    return 0;
}