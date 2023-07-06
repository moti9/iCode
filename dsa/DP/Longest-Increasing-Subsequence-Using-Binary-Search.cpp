#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> subseq;

        int maxLen = 1;
        subseq.push_back(arr[0]);

        for (int ind = 1; ind < n; ind++)
        {
            if (arr[ind] > subseq.back())
            {
                subseq.push_back(arr[ind]);
            }
            else
            {
                int index = lower_bound(subseq.begin(), subseq.end(), arr[ind]) - subseq.begin();
                subseq[index] = arr[ind];
            }

            maxLen = max(maxLen, (int)subseq.size());
        }

        return maxLen;
    }
};

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
