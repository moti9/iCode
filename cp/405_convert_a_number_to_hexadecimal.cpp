#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    string toHex(int num)
    {
        uint32_t n = static_cast<uint32_t>(num);
        string hexChars = "0123456789abcdef";
        string answer = "";
        while (n)
        {
            answer = hexChars[n % 16] + answer;
            n >>= 4;
        }
        return answer;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Solution sol;
    cout << sol.toHex(n) << endl;

    return 0;
}