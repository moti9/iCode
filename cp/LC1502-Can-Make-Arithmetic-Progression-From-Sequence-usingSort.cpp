#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Usinnnnnnnnng Sort
// TC- O(NlogN)
// SC- O(1)

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        int n = arr.size();
        for (int i = 2; i < n; i++)
        {
            int d = arr[i] - arr[i - 1];
            if (d != diff)
            {
                return false;
            }
        }
        return true;
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