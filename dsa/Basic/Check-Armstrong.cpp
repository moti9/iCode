#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool checkArmstrong(int n)
{
    string num = to_string(n);
    int digits = num.length();
    int sum = 0;
    for (int i = 0; i < digits; i++)
    {
        sum += pow(num[i] - '0', digits);
    }
    return n == sum;
}

int main()
{
    int n;
    cin >> n;

    cout << checkArmstrong(n) << endl;

    return 0;
}