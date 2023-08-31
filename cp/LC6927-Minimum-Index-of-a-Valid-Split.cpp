#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        int major = -1;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] += 1;
        }
        for (auto &x : mp)
        {
            if (x.second > (n / 2))
            {
                major = x.first;
            }
        }

        if (major == -1)
        {
            return -1;
        }
        int cntMajor = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == major)
            {
                cntMajor += 1;
            }
            int leftSize = i + 1;
            int rightSize = n - i - 1;
            int rightCnt = mp[major] - cntMajor;
            if (cntMajor > (leftSize / 2.0) && rightCnt > (rightSize / 2.0))
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}

/*

int findMajority(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]] += 1;
        }
        for (auto &x : mp)
        {
            if (x.second > (n / 2))
            {
                return x.first;
            }
        }
        return -1;
    }

    int checkMajority(int start, int end, int ele, vector<int> &nums)
    {
        int n = end - start;
        unordered_map<int, int> mp;

        for (int i = start; i < end; i++)
        {
            mp[nums[i]] += 1;
        }
        int cnt = mp[ele];
        for (auto &x : mp)
        {
            if (cnt < x.second)
            {
                return false;
            }
        }
        return true;
    }

*/