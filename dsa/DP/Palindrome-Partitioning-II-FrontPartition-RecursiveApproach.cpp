#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int isPalindrome(int i, int j, string &str)
    {
        while (i < j)
        {
            if (str[i] != str[j])
            {
                return 0;
            }
            i += 1;
            j -= 1;
        }
        return 1;
    }
    
    int makePartitions(int i, int n, string &str)
    {
        if (i == n)
        {
            return 0;
        }
        int minParts = n;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str) == 1)
            {
                int parts = 1 + makePartitions(j + 1, n, str);
                minParts = min(minParts, parts);
            }
        }
        return minParts;
    }

public:
    int minCut(string str)
    {
        int n = str.length();
        return makePartitions(0, n, str) - 1;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution sol;
    cout << sol.minCut(s) << endl;

    return 0;
}