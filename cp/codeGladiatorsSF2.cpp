#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    ll generateLists(const string &s, int start, unordered_map<ll, ll> &memo, int k)
    {
        if (start >= s.length())
        {
            return 1;
        }

        if (memo.find(start) != memo.end())
        {
            return memo[start];
        }

        ll count = 0;

        for (int length = 1; length <= s.length() - start; ++length)
        {
            string numStr = s.substr(start, length);
            if (numStr.length() > 1 && numStr[0] == '0')
                break;
            int num = stoi(numStr);
            if (num >= 1 && num <= k)
            {
                count = (count + generateLists(s, start + length, memo, k)) % mod;
            }
        }

        // Memoize the result
        memo[start] = count;
        return count;
    }

public:
    int countPossibleArrays(int n, int k, string &s)
    {
        unordered_map<ll, ll> memo;
        return generateLists(s, 0, memo, k);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    Solution sol;
    cout << sol.countPossibleArrays(n, k, s) << "\n";

    return 0;
}