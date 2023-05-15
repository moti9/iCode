#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimized Approach :)
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        unordered_map<int, int> mp;
        int maxlen = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum == 0)
            {
                maxlen = max(maxlen, i + 1);
            }
            else
            {
                if (mp.find(sum) != mp.end())
                {
                    maxlen = max(maxlen, i - mp[sum]);
                }
                else
                {
                    mp[sum] = i;
                }
            }
        }
        return maxlen;
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
    cout << sol.maxLen(arr, n) << endl;

    return 0;
}