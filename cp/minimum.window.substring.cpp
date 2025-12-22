#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.size();
        int n = t.size();
        if (m < n)
            return "";
        unordered_map<char, int> freq;
        for (char c : t)
            freq[c]++;
        int left = 0, right = 0;
        int count = freq.size();
        int minLen = INT_MAX;
        int startIndex = -1;
        while (right < m)
        {
            char currChar = s[right];
            if (freq.find(currChar) != freq.end())
            {
                freq[currChar]--;
                if (freq[currChar] == 0)
                    count--;
            }
            right++;
            while (count == 0)
            {
                if (right - left < minLen)
                {
                    minLen = right - left;
                    startIndex = left;
                }
                char leftChar = s[left];
                if (freq.find(leftChar) != freq.end())
                {
                    freq[leftChar]++;
                    if (freq[leftChar] > 0)
                        count++;
                }
                left++;
            }
        }
        if (startIndex == -1)
            return "";
        return s.substr(startIndex, minLen);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;

    Solution sol = Solution();
    string result = sol.minWindow(s, t);
    cout << result << "\n";

    return 0;
}