#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles)
    {
        int n = obstacles.size();
        vector<int> ans(n, 1), lis;
        for (int i = 0; i < n; i++)
        {
            int index = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if (index == lis.size())
            {
                lis.push_back(obstacles[i]);
            }
            else
            {
                lis[index] = obstacles[i];
            }
            ans[i] = index + 1;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> obstacles(n);
    for (int i = 0; i < n; i++)
    {
        cin >> obstacles[i];
    }
    Solution sol;
    vector<int> ans = sol.longestObstacleCourseAtEachPosition(obstacles);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}