#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int addMinimum(string word)
    {
        int n = word.size();
        int ans = 0;
        int i = 0;
        while (i < n)
        {
            int cnt = 0;
            if (word[i] == 'a')
            {
                cnt++;
                i++;
            }
            if (i < n && word[i] == 'b')
            {
                cnt++;
                i++;
            }
            if (i < n && word[i] == 'c')
            {
                cnt++;
                i++;
            }
            ans += (3 - cnt);
        }
        return ans;
    }
};

int main()
{
    string word;
    cin >> word;
    Solution sol;
    cout << sol.addMinimum(word) << endl;

    return 0;
}