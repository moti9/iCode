#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printDivisors(int n, unordered_map<int, int> &mp)
{
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                mp[i] += 1;

            else
            {
                mp[i] += 1;
                mp[n / i] += 1;
            }
        }
    }
}
int solve(int N, int K, vector<int> nums)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
    {
        printDivisors(nums[i], mp);
    }
    int ans = -1;
    for (auto &x : mp)
    {
        if (x.second >= K)
            ans = max(ans, x.first);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << solve(n, k, nums) << endl;

    return 0;
}