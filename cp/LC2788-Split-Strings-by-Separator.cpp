#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<string> splitWordsBySeparator(vector<string> &words, char separator)
    {
        vector<string> ans;
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            int m = words[i].length();
            string temp = "";
            for (int j = 0; j < m; j++)
            {
                if (words[i][j] == separator)
                {
                    if (temp != "")
                    {
                        ans.push_back(temp);
                        temp = "";
                    }
                }
                else
                {
                    temp += words[i][j];
                }
            }
            if (temp != "")
            {
                ans.push_back(temp);
                temp = "";
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    char separator;
    cin >> separator;

    Solution sol;
    vector<string> ans = sol.splitWordsBySeparator(words, separator);
    for (auto &a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}