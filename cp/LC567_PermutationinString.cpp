#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Greedy Approach
/*
class Solution
{
    bool check(string &s1, string &s2)
    {
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();
        if (n < m)
        {
            return false;
        }
        sort(s1.begin(), s1.end());
        for (int i = 0; i <= n - m; i++)
        {
            string st = s2.substr(i, m);
            if (check(s1, st))
            {
                return true;
            }
        }
        return false;
    }
};
*/


class Solution
{
    bool check(int arr1[], int arr2[])
    {
        for (int k = 0; k < 26; k++)
        {
            if (arr1[k] != arr2[k])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        if (m > n)
            return false;
        int arr1[26] = {0};
        int arr2[26] = {0};

        for (int i = 0; i < m; i++)
        {
            arr1[s1[i] - 'a']++;
        }

        for (int i = 0; i < m; i++)
        {
            arr2[s2[i] - 'a']++;
        }
        if (check(arr1, arr2))
            return true;

        for (int i = m; i < n; i++)
        {
            arr2[s2[i - m] - 'a']--;
            arr2[s2[i] - 'a']++;
            if (check(arr1, arr2))
                return true;
        }
        return false;
    }
};

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    Solution sol;
    cout << sol.checkInclusion(s1, s2) << endl;

    return 0;
}