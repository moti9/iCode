#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int sumOfDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int sumOfAllDivisors(int n)
{
    int totalSum = 0;
    for (int i = 1; i <= n; i++)
    {
        totalSum += sumOfDivisors(i);
    }
    return totalSum;
}////////

int main()
{
    int n;
    cin >> n;

    cout << sumOfAllDivisors(n) << endl;

    return 0;
}