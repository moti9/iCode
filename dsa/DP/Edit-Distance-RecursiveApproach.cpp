#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int countOperations(int i, int j, string &str1, string &str2)
    {
        if (j < 0)
        {
            return i + 1;
        }
        if (i < 0)
        {
            return j + 1;
        }

        if (str1[i] == str2[j])
        {
            return 0 + countOperations(i - 1, j - 1, str1, str2);
        }
        else
        {
            int opr = 1 + countOperations(i, j - 1, str1, str2);
            opr = min(opr, 1 + countOperations(i - 1, j, str1, str2));
            opr = min(opr, 1 + countOperations(i - 1, j - 1, str1, str2));
            return opr;
        }
    }

public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        return countOperations(n - 1, m - 1, word1, word2);
    }
};

int main()
{
    string word1, word2;
    cin >> word1 >> word2;

    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;

    return 0;
}