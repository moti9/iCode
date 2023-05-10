#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Optimal Approach (Extended Boyer Moore’s Voting Algorithm):
// TC- O(N+N)
// SC- O(1)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int ele1 = -1, ele2;
        int cnt1 = 0, cnt2 = 0;
        for (auto num : nums)
        {
            if (cnt1 == 0 && ele2 != num)
            {
                ele1 = num;
            }
            else if (cnt2 == 0 && ele1 != num)
            {
                ele2 = num;
            }
            if (ele1 == num)
                cnt1 += 1;
            else if (ele2 == num)
                cnt2 += 1;
            else
                cnt1 -= 1, cnt2 -= 1;
        }
        cnt1 = 0;
        cnt2 = 0;
        for (auto num : nums)
        {
            if (num == ele1)
                cnt1++;
            if (num == ele2)
                cnt2++;
        }
        vector<int> majority;
        if (cnt1 > nums.size() / 3)
            majority.push_back(ele1);
        if (cnt2 > nums.size() / 3)
            majority.push_back(ele2);
        return majority;
    }
};

// Using HashMap
// TC- O(N+N)
// SC- O(N)

/*
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int n = nums.size();
        int major = (n / 3) + 1;
        vector<int> majority;
        for (auto num : nums)
        {
            mp[num] += 1;
            if (mp[num] == major)
                majority.push_back(num);
            if (majority.size() == 2)
                break;
        }
        return majority;
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
    vector<int> majorityElement(vector<int> &nums)
    {
        int majoritycnt = nums.size() / 3;
        vector<int> majority;
        for (int num : nums)
        {
            if (majority.size() == 0 || majority[0] != num)
            {

                int count = 0;
                for (int elem : nums)
                {
                    if (elem == num)
                    {
                        count += 1;
                    }
                }

                if (count > majoritycnt)
                {
                    majority.push_back(num);
                }
            }
            if (majority.size() == 2)
                break;
        }

        return majority;
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
    vector<int> ans = sol.majorityElement(nums);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}