#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimized Approach
// TC- O(2*N), ometimes left and right both have to travel a complete array
// SC- O(N)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        int n = s.length();
        unordered_set<int> st;
        int left = 0;
        for (int right = 0; right < n; right++)
        {
            if (st.find(s[right]) != st.end())
            {
                while (left < right && st.find(s[right]) != st.end())
                {
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[right]);
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