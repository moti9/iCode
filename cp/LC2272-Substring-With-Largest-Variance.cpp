#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int largestVariance(string s)
    {
        vector<int> freq(26, 0);
        for (auto &ch : s)
        {
            freq[ch - 'a'] += 1;
        }

        int maxVar = 0;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (freq[i] == 0 || freq[j] == 0)
                {
                    continue;
                }
                char first = i + 'a';
                char second = j + 'a';
                int firstCnt = 0, secondCnt = 0;
                bool pastSecond = false;
                
                for (auto &ch : s)
                {
                    if (first == ch)
                    {
                        firstCnt += 1;
                    }
                    if (second == ch)
                    {
                        secondCnt += 1;
                    }

                    if (secondCnt > 0)
                    {
                        maxVar = max(maxVar, firstCnt - secondCnt);
                    }
                    else if (pastSecond == true)
                    {
                        maxVar = max(maxVar, firstCnt - 1);
                    }

                    if (secondCnt > firstCnt)
                    {
                        firstCnt = 0;
                        secondCnt = 0;
                        pastSecond = true;
                    }
                }
            }
        }
        return maxVar;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.largestVariance(s) << endl;

    return 0;
}