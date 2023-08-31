#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0))
        {
            return false;
        }

        unsigned int reversedNum = 0;
        int originalNum = x;

        while (x > 0)
        {
            reversedNum = reversedNum * 10 + x % 10;
            x /= 10;
        }

        return originalNum == reversedNum;
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.isPalindrome(n) << endl;

    return 0;
}