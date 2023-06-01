#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int solve(int ind, int n, int k, vector<int> &arr, unordered_map<int, int> &mp, vector<int> &dp)
    {
        if (ind >= n)
        {
            return mp.size();
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int ans = n + 1;
        int temp = arr[ind] + k;
        mp.erase(arr[ind]);
        mp[temp]++;
        int cnt = solve(ind + 1, n, k, arr, mp, dp);
        ans = max(ans, cnt);
        mp.erase(temp);
        mp[arr[ind]]++;

        temp = arr[ind] - k;
        mp.erase(arr[ind]);
        mp[temp]++;
        cnt = solve(ind + 1, n, k, arr, mp, dp);
        ans = max(ans, cnt);
        mp.erase(temp);
        mp[arr[ind]]++;

        cnt = solve(ind + 1, n, k, arr, mp, dp);
        ans = max(ans, cnt);

        return dp[ind] = ans;
    }

public:
    int distinctElements(int N, int K, vector<int> A)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
        {
            mp[A[i]]++;
        }
        vector<int> dp(N + 1, -1);

        return solve(0, N, K, A, mp, dp);
    }
};

int main()
{

    return 0;
}