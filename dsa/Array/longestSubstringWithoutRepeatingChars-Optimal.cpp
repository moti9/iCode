#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimal Approach
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        int n = s.length();
        vector<int> freq(26, -1);
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (freq[s[right] - 'a'] != -1)
            {
                left = max(left, freq[s[right] - 'a'] + 1);
            }
            freq[s[right] - 'a'] = right;

            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}