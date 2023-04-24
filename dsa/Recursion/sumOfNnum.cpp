#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int sumUsingPara(int n, int sum)
{
    if (n < 1)
    {
        return sum;
    }
    return sumUsingPara(n - 1, sum + n);
}

int sumUsingFunc(int n)
{
    if (n < 1)
    {
        return 0;
    }
    return n + sumUsingFunc(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << "Sum using parameterised recursion : " << sumUsingPara(n, 0) << endl;
    cout << "Sum using functional recursion : " << sumUsingFunc(n) << endl;

    return 0;
}