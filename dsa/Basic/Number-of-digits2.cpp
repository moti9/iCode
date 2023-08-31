#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int countDigits(int n)
{
    string num = to_string(n);
    return num.length();
}

int main()
{
    int n;
    cin >> n;

    cout << countDigits(n) << endl;

    return 0;
}