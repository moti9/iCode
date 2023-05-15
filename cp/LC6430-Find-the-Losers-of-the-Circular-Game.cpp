#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> circularGameLosers(int n, int k)
    {
        unordered_map<int, int> mp;
        int curr = 1;
        int step = k;
        while (true)
        {
            mp[curr]++;
            int next = (curr + step) % (n);
            if (next == 0)
            {
                next = n;
            }
            if (mp.find(next) != mp.end())
            {
                break;
            }
            curr = next;
            step += k;
        }
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (mp[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    Solution sol;
    vector<int> ans = sol.circularGameLosers(n, k);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}