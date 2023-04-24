#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        set<int> s;
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                s.insert(num);
            }
            else
            {
                s.insert(num * 2);
            }
        }
        int minimum_deviation = INT_MAX;
        while (!s.empty())
        {
            int max_num = *s.rbegin();
            int min_num = *s.begin();
            minimum_deviation = min(minimum_deviation, max_num - min_num);
            if (max_num % 2 == 0)
            {
                s.erase(max_num);
                s.insert(max_num / 2);
            }
            else
            {
                break;
            }
        }
        return minimum_deviation;
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
    cout << sol.minimumDeviation(nums) << endl;

    return 0;
}