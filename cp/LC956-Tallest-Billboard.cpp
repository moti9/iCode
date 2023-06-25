#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (auto &r : rods)
        {
            unordered_map<int, int> curr(dp);
            for (auto &itr : dp)
            {
                int diff = itr.first;
                int taller = itr.second;
                int shorter = taller - diff;

                int newDiff = diff + r;
                int newTaller = taller + r;
                curr[newDiff] = max(curr[newDiff], newTaller);

                newDiff = abs(shorter + r - taller);
                newTaller = max(shorter + r, taller);

                curr[newDiff] = max(curr[newDiff], newTaller);
            }
            dp = curr;
        }
        return dp[0];
    }
};

/*
class Solution
{
    struct hash_pair
    {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> &p) const
        {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            return hash1 ^ hash2;
        }
    };

    unordered_map<int, int> helper(int left, int right, vector<int> &rods)
    {
        unordered_set<pair<int, int>, hash_pair> states;
        states.insert({0, 0});
        for (int i = left; i < right; i++)
        {
            int r = rods[i];
            unordered_set<pair<int, int>, hash_pair> newStates;
            for (auto &p : states)
            {
                newStates.insert({p.first + r, p.second});
                newStates.insert({p.first, p.second + r});
            }
        }
        unordered_map<int, int> dp;
        for (auto &p : states)
        {
            int lt = p.first, rt = p.second;
            dp[lt - rt] = max(dp[lt - rt], lt);
        }
        return dp;
    }

public:
    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        unordered_map<int, int> left = helper(0, n / 2, rods);
        unordered_map<int, int> right = helper(n / 2, n, rods);

        int ans = 0;
        for (auto &diff : left)
        {
            if (right.find(-diff.first) != right.end())
            {
                ans = max(ans, diff.second + right[-diff.first]);
            }
        }
        return ans;
    }
};

 */

/*
class Solution
{
    int findHeight(int ind, int rod1, int rod2, vector<int> &rods)
    {
        if (ind == 0)
        {
            if (rod1 == rod2)
            {
                return rod1;
            }
            else if (rod1 + rods[0] == rod2)
            {
                return rod2;
            }
            else if (rod1 == rod2 + rods[0])
            {
                return rod1;
            }
            return -1e7;
        }

        int maxHeight = 0;
        maxHeight = max(maxHeight, findHeight(ind - 1, rod1, rod2, rods));
        maxHeight = max(maxHeight, findHeight(ind - 1, rod1 + rods[ind], rod2, rods));
        maxHeight = max(maxHeight, findHeight(ind - 1, rod1, rod2 + rods[ind], rods));

        return maxHeight;
    }

public:
    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size();
        return findHeight(n - 1, 0, 0, rods);
    }
};

*/

int main()
{
    int n;
    cin >> n;
    vector<int> rods(n);
    for (int i = 0; i < n; i++)
    {
        cin >> rods[i];
    }

    Solution sol;
    cout << sol.tallestBillboard(rods) << endl;

    return 0;
}