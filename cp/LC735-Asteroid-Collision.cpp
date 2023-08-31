#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (int &curr : asteroids)
        {
            while (!ans.empty() && ans.back() > 0 && ans.back() < -curr)
            {
                ans.pop_back();
            }
            if (ans.empty() || curr > 0 || ans.back() < 0)
            {
                ans.push_back(curr);
            }
            else if (ans.back() == -curr)
            {
                ans.pop_back();
            }
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> asteroids(n);
    for (int i = 0; i < n; i++)
    {
        cin >> asteroids[i];
    }

    Solution sol;
    vector<int> ans = sol.asteroidCollision(asteroids);

    for (auto &a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}