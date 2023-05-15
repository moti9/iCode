#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Brute force Approach
// TC- O(N*N)
// SC- O(N)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            for (int j = i; j < n; j++)
            {
                if (st.find(s[j]) != st.end())
                {
                    maxlen = max(maxlen, j - i);
                    break;
                }
                st.insert(s[j]);
            }
            maxlen = max(maxlen, (int)st.size());
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