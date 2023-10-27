#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    const int MOD = 1e9 + 7;

public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        int n = arr.size();
        long result = 0;
        sort(arr.begin(), arr.end());
        map<int, long> mp;
        mp[arr[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            long cnt = 1;
            for (auto &x : mp)
            {
                int ele = x.first;
                if (arr[i] % ele == 0 && mp.find(arr[i] / ele) != mp.end())
                {
                    cnt += (mp[ele] * mp[arr[i] / ele]);
                }
            }
            mp[arr[i]] = (cnt % MOD);
        }
        for (auto &x : mp)
        {
            result = (result + x.second) % MOD;
        }
        return (int)result;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.numFactoredBinaryTrees(arr) << endl;

    return 0;
}