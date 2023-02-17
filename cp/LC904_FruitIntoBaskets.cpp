#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int ans = 0;
        int n = fruits.size();
        vector<int> basket(2, -1);
        for (int i = 0; i < n; i++)
        {
            int ct = 0;
            vector<int> temp = basket;
            for (int j = i; j < n; j++)
            {
                if (temp[0] == fruits[j] || temp[1] == fruits[j])
                {
                    ct++;
                }
                else if (temp[0] == -1)
                {
                    temp[0] = fruits[j];
                    ct++;
                }
                else if (temp[1] == -1)
                {
                    temp[1] = fruits[j];
                    ct++;
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, ct);
            // cout << ans << endl;
            if (n - i - 1 <= ans)
            {
                break;
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> fruits(n);
    for (int i = 0; i < n; i++)
    {
        cin >> fruits[i];
    }
    Solution sol;
    cout << sol.totalFruit(fruits) << endl;

    return 0;
}