#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 1)
        {
            return n;
        }
        if (n == 2)
        {
            return 1;
        }
        int a = 0, b = 1, c = 1, curr;
        for (int i = 3; i <= n; i++)
        {
            curr = a + b + c;
            a = b;
            b = c;
            c = curr;
        }
        return curr;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    cout << sol.tribonacci(n) << endl;

    return 0;
}