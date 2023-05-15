#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// (Naive approach) :)
// TC- O(N*N)
// SC- O(1)

class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        int maxlen = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == 0)
                {
                    maxlen = max(maxlen, j - i + 1);
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