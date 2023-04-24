// 6331. Maximize Win From Two Segments

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maximizeWin(vector<int> &prizePositions, int k)
    {
        int n = prizePositions.size();
        int diff = prizePositions[n - 1] - prizePositions[0];
        if (k >= diff)
        {
            return n;
        }
        unordered_map<int, int> mp;
        for (auto x : prizePositions)
            mp[x]++;
        vector<int> collect;
        int st = prizePositions[0];
        int end = prizePositions[n - 1];
        for (int i = st; i <= end - k; i++)
        {
            int sum = 0;
            for (int j = i; j <= i + k; j++)
            {
                if (j <= end && j >= st)
                {
                    sum += mp[j];
                }
                else
                {
                    break;
                }
            }
            if (sum)
            {
                collect.push_back(sum);
            }
        }
        sort(collect.begin(), collect.end());
        int sz = collect.size();
        return sz >= 2 ? collect[sz - 1] + collect[sz - 2] : 2 * collect[sz];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    int k;
    cin >> k;
    Solution sol;
    cout << sol.maximizeWin(pos, k) << endl;

    return 0;
}

*/

// 6304. Maximum Number of Integers to Choose From a Range I

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mod 1000000007

// class Solution
// {
// public:
//     int maxCount(vector<int> &banned, int n, int maxSum)
//     {
//     }
// };

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int> banned(n);
//     for(int i=0;i<n;i++){}

//     return 0;
// }

// 6305. Disconnect Path in a Binary Matrix by at Most One Flip

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool markPath(int n, int m, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
        {
            if (n == 0 && m == 0)
                return dp[n][m] = 1;
            return dp[n][m] = 0;
        }
        if (dp[n][m] == 0)
            dp[n][m] = markPath(n - 1, m, dp) + markPath(n, m - 1, dp);

        return dp[n][m];
    }

public:
    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        markPath(n, m, dp);
        for (int i = 1; i < n - 1; i++)
        {
            int ct = 0;
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && dp[i][j] == 1)
                {
                    ct++;
                }
            }
            if (ct <= 1)
            {
                return true;
            }
        }

        for (int i = 1; i < m - 1; i++)
        {
            int ct = 0;
            for (int j = 0; j < n; j++)
            {
                if (grid[j][i] == 1 && dp[i][j] == 1)
                {
                    ct++;
                }
            }
            if (ct <= 1)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    cout << sol.isPossibleToCutPath(grid) << endl;

    return 0;
}
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        long long ans = 0;
        int n = gifts.size();

        while (k--)
        {
            int mi = 0;
            for (int j = 0; j < n; j++)
            {
                if (gifts[mi] < gifts[j])
                {
                    mi = j;
                }
            }
            gifts[mi] = floor(sqrt(gifts[mi]));
        }
        for (int i = 0; i < n; i++)
        {
            // cout<<gifts[i]<<" ";
            ans += (long long)gifts[i];
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> gifts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> gifts[i];
    }
    int k;
    cin >> k;
    Solution sol;
    cout << sol.pickGifts(gifts, k) << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool check(string &s)
    {
        int n = s.size();
        char l = s[n - 1];
        char st = s[0];
        if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')
        {
            if (st == 'a' || st == 'e' || st == 'i' || st == 'o' || st == 'u')
            {
                return true;
            }
        }
        return false;
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int n = words.size();
        vector<bool> vowel(n);
        for (int i = 0; i < n; i++)
        {
            if (check(words[i]))
            {
                vowel[i] = true;
            }
        }
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++)
        {
            int ct = 0;
            for (int j = queries[i][0]; j <= queries[i][1]; j++)
            {
                ct += vowel[j];
            }
            ans[i] = ct;
        }
        return ans;
    }
};

int main()
{

    return 0;
}