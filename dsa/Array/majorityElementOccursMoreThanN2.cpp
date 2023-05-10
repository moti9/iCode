#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Boyer-Moore Voting Algorithm
// TC- O(N+N)
// SC- O(1)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majorityEle = -1;
        int cnt = 0;
        for (auto num : nums)
        {
            if (cnt == 0)
            {
                majorityEle = num;
            }
            if (majorityEle == num)
                cnt += 1;
            else
                cnt -= 1;
        }
        cnt = 0;
        for (auto num : nums)
        {
            if (num == majorityEle)
                cnt++;
        }

        if (cnt > (nums.size() / 2))
            return majorityEle;
        return -1;
    }
};

// Using Bit manipulation
// TC- O(NlgM)--M=max(nums)
// SC- O(1)
/*
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int majorityEle = 0;
        for (int i = 0; i < 32; i++)
        {
            int bit = 1 << i;
            int bitcnt = 0;
            for (auto num : nums)
            {
                if (num & bit)
                {
                    bitcnt += 1;
                }
            }
            if (bitcnt > n / 2)
            {
                majorityEle |= bit;
            }
        }
        return majorityEle;
    }
};
*/

// Using sorting
// TC- O(NlogN)
// SC- O(1)
/*
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
*/

// Using HashMap
// TC- O(N+N)
// SC- O(N)
/*
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (auto x : nums)
            mp[x] += 1;
        for (auto m : mp)
        {
            if (m.second > n / 2)
                return m.first;
        }
        return -1;
    }
};
*/

// Brute Force
// TC- O(N*N)
// SC- O(1)
/*
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int majorityCount = nums.size() / 2;

        for (int num : nums)
        {
            int count = 0;
            for (int elem : nums)
            {
                if (elem == num)
                {
                    count += 1;
                }
            }

            if (count > majorityCount)
            {
                return num;
            }
        }

        return -1;
    }
};
*/

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
    cout << sol.majorityElement(nums) << endl;

    return 0;
}