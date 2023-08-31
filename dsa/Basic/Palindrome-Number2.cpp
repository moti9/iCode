#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isPalindrome(int x)
    {
        string num = to_string(x);

        int left = 0, right = num.length() - 1;
        while (left < right)
        {
            if (num[left] != num[right])
            {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
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