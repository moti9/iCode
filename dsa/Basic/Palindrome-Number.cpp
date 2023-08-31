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
        string rev(num.rbegin(), num.rend());
        // if(rev.back() == '-')
        // {
        //     rev.pop_back();
        //     rev = '-' + rev;
        // }
        return num == rev;
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