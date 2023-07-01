#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findunfairness(int ind, int k, int n, vector<int> &cookies, vector<int> &children)
    {
        if (ind == n)
        {
            int unfair = 0;
            for (auto ch : children)
            {
                unfair = max(unfair, ch);
            }
            return unfair;
        }

        int minUnfair = 1e9;
        for (int i = 0; i < k; i++)
        {
            children[i] += cookies[ind];
            minUnfair = min(minUnfair, findunfairness(ind + 1, k, n, cookies, children));
            children[i] -= cookies[ind];
        }
        return minUnfair;
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        int n = cookies.size();
        vector<int> children(k, 0);
        return findunfairness(0, k, n, cookies, children);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> cookies(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cookies[i];
    }

    int k;
    cin >> k;

    Solution sol;
    cout << sol.distributeCookies(cookies, k) << endl;

    return 0;
}