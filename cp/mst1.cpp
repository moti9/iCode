#include <bits/stdc++.h>
#include<vector>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;
    return true;
}

int solve(int n, int k)
{
    int c = 0;
    vector<int> lst;

    for (int i = n + 1; c < k; i++)
    {
        int temp = i;
        int sum = 0;
        while (temp != 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (isPrime(sum))
        {
            lst.push_back(i);
            c++;
        }
    }
    return lst[k - 1];
}
int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    cout << solve(n, k);

    return 0;
}