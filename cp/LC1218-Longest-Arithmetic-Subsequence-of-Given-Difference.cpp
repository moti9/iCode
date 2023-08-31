#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        int n = arr.size();
        unordered_map<int, int> prevSeq;
        int maxLen = 1;
        for (int i = 0; i < n; i++)
        {
            int prev = arr[i] - difference;
            if (prevSeq.find(prev) != prevSeq.end())
            {
                prevSeq[arr[i]] = 1 + prevSeq[prev];
            }
            else
            {
                prevSeq[arr[i]] = 1;
            }
            maxLen = max(maxLen, prevSeq[arr[i]]);
        }
        return maxLen;
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

    int diff;
    cin >> diff;

    Solution sol;
    cout << sol.longestSubsequence(arr, diff) << endl;

    return 0;
}