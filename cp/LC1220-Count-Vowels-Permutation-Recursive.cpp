#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int solve(string s, int n)
    {
        if (s.length() == n)
        {
            return 1;
        }
        int cnt = 0;
        if (s == "")
        {
            cnt += solve(s + 'a', n);
            cnt += solve(s + 'e', n);
            cnt += solve(s + 'i', n);
            cnt += solve(s + 'o', n);
            cnt += solve(s + 'u', n);
        }
        else
        {
            char prev = s.back();
            if (prev == 'a')
            {
                cnt += solve(s + 'e', n);
            }
            else if (prev == 'e')
            {
                cnt += solve(s + 'a', n);
                cnt += solve(s + 'i', n);
            }
            else if (prev == 'i')
            {
                cnt += solve(s + 'a', n);
                cnt += solve(s + 'e', n);
                cnt += solve(s + 'o', n);
                cnt += solve(s + 'u', n);
            }
            else if (prev == 'o')
            {
                cnt += solve(s + 'i', n);
                cnt += solve(s + 'u', n);
            }
            else if (prev == 'u')
            {
                cnt += solve(s + 'a', n);
            }
        }
        return cnt;
    }

public:
    int countVowelPermutation(int n)
    {
        return solve("", n);
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.countVowelPermutation(n) << endl;

    return 0;
}