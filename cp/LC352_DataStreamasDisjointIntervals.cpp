#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void print(vector<vector<int>> &intervals)
{
    for (auto x : intervals)
    {
        cout << x[0] << " " << x[1] << "\n";
    }
}
class SummaryRanges
{
    map<int, int> mp;

public:
    SummaryRanges()
    {
        mp.clear();
    }

    void addNum(int value)
    {
        int left = value, right = value;

        auto next = mp.upper_bound(value);

        if (next != mp.begin())
        {
            auto prev = next;
            prev--;

            if (prev->second >= value)
            {
                return;
            }

            if (prev->second == value - 1)
            {
                left = prev->first;
            }
        }

        if (next != mp.end() && next->first == value + 1)
        {
            right = next->second;
            mp.erase(next->first);
        }

        mp[left] = right;
    }

    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        for (auto &it : mp)
        {
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};

// class SummaryRanges
// {
//     set<int> st;

// public:
//     SummaryRanges()
//     {
//         st.clear();
//     }

//     void addNum(int value)
//     {
//         st.insert(value);
//     }

//     vector<vector<int>> getIntervals()
//     {
//         vector<int> nums(st.begin(), st.end());
//         vector<vector<int>> ans;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int left = nums[i];
//             while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
//             {
//                 i += 1;
//             }
//             ans.push_back({left, nums[i]});
//         }
//         return ans;
//     }
// };

int main()
{
    int n;
    cin >> n;
    SummaryRanges *sr;
    for (int i = 0; i < n; i++)
    {
        string stm;
        cin >> stm;
        if (stm == "SummaryRanges")
        {
            sr = new SummaryRanges();
        }
        else if (stm == "addNum")
        {
            int num;
            cin >> num;
            sr->addNum(num);
        }
        else if (stm == "getIntervals")
        {
            vector<vector<int>> ans = sr->getIntervals();
            print(ans);
        }
    }

    return 0;
}