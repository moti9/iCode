#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Greedy Approach
/*
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
        {
            return s;
        }
        int n = s.size();
        string ans = "";
        vector<char> ch[numRows];
        bool col = 1;
        for (int i = 0; i < n;)
        {
            if (col)
            {
                for (int j = 0; j < numRows && i < n; j++)
                {
                    ch[j].push_back(s[i]);
                    i++;
                }
                col = 0;
            }
            else
            {
                if (numRows > 2)
                {
                    for (int j = numRows - 2; j > 0 && i < n; j--)
                    {
                        ch[j].push_back(s[i]);
                        i++;
                    }
                }
                col = 1;
            }
        }
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < ch[i].size(); j++)
            {
                ans += ch[i][j];
            }
        }
        return ans;
    }
};
*/

class Solution
{
public:
    string convert(string s, int num)
    {
        if (s.length() == 0 || num == 1)
            return s;
        string a[num];
        string ans = "";
        int row = 0;
        bool down = true;
        for (int i = 0; i < s.length(); i++)
        {
            a[row].push_back(s[i]);
            if (row == 0)
                down = true;
            else if (row == num - 1)
                down = false;
            if (down)
                row++;
            else
                row--;
        }
        for (int i = 0; i < num; i++)
        {
            ans += a[i];
        }
        return ans;
    }
};

int main()
{
    string s;
    cin >> s;
    int numRow;
    cin >> numRow;
    Solution sol;

    cout << sol.convert(s, numRow) << endl;

    return 0;
}