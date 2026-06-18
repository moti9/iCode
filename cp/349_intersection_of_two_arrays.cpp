
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> ust;
        for (int &num : nums1)
            ust.insert(num);
        vector<int> ans;
        for (int &num : nums2)
            if (ust.find(num) != ust.end())
                ans.push_back(num), ust.erase(num);

        return ans;
    }
};