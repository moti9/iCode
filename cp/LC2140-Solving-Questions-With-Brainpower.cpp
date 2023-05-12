#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Dp- Iterative
// TC- O(N)
// SC- O(N)

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n);
        dp[n - 1] = questions[n - 1][0];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = questions[i][0];
            int skip = questions[i][1];
            if (i + skip + 1 < n)
                dp[i] += dp[i + skip + 1];
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};

// Dp- Recursive(Memoization)

// TC- O(N)
// SC- O(N)

/*
class Solution
{
    long long solve(int ind, int n, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];
        long long ans = 0;
        long long sp = (long long)questions[ind][0];
        sp += solve(ind + questions[ind][1] + 1, n, questions, dp);

        long long nsp = 0;
        nsp += solve(ind + 1, n, questions, dp);
        ans = max(sp, nsp);
        return dp[ind] = ans;
    }

public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(0, n, questions, dp);
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> questions;
    for (int i = 0; i < n; i++)
    {
        int p, b;
        cin >> p >> b;
        questions.push_back({p, b});
    }

    Solution sol;
    cout << sol.mostPoints(questions) << endl;

    return 0;
}