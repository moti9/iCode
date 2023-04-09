#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n, 0);
        sort(potions.begin(), potions.end());
        int maxPotion = potions[m - 1];
        for (int i = 0; i < n; i++)
        {
            int minPotion = ceil(1.0 * success / spells[i]);
            auto ind = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();
            ans[i] += (m - ind);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> spells(n);
    for (int i = 0; i < n; i++)
    {
        cin >> spells[i];
    }
    int m;
    cin >> m;
    vector<int> potions(m);
    for (int i = 0; i < m; i++)
    {
        cin >> potions[i];
    }
    ll success;
    cin >> success;
    Solution sol;
    vector<int> ans = sol.successfulPairs(spells, potions, success);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}