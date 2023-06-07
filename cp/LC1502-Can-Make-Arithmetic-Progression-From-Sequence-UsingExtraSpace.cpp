#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Extra space
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        int a0 = *min_element(arr.begin(), arr.end());
        int an = *max_element(arr.begin(), arr.end());
        int n = arr.size();
        if (an - a0 == 0)
        {
            return true;
        }
        if ((an - a0) % (n - 1))
        {
            return false;
        }
        int diff = (an - a0) / (n - 1);
        unordered_set<int> nums;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i] - a0) % diff)
            {
                return false;
            }
            nums.insert(arr[i]);
        }
        return nums.size() == n;
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
    cout << sol.canMakeArithmeticProgression(arr) << endl;

    return 0;
}