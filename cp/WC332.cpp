

// 2564. Substring XOR Queries

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>> &queries)
    {
    }
};

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<vector<int>> queries(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }

    Solution sol;

    vector<vector<int>> ans = sol.substringXorQueries(s, queries);

    for (auto &x : ans)
    {
        cout << x[0] << x[1] << endl;
    }

    return 0;
}

// 6355. Count the Number of Fair Pairs

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        int n = nums.size();
        long long ct = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            ct += (long long)(right - left);
        }
        return ct;
    }
};

long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    int n = nums.size();
    long long ct = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = nums[i] + nums[j];
            if (sum >= lower && sum <= upper)
                ct += 1;
        }
    }
    return ct;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int lower, upper;
    cin >> lower >> upper;
    Solution sol;
    cout << sol.countFairPairs(nums, lower, upper) << endl;

    return 0;
}
*/

// 6354. Find the Array Concatenation Value

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ans = 0;
        int n = nums.size();
        if (n % 2)
            ans += (long long)nums[n / 2];
        for (int i = 0; i < n / 2; i++)
        {
            string s = to_string(nums[i]) + to_string(nums[n - i - 1]);
            ans += (long long)stoi(s);
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.findTheArrayConcVal(nums) << endl;

    return 0;
}
*/