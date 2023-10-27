#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    struct Element
    {
        int val;
        int arrInd;
        int valInd;
        Element(int v, int ai, int vi) : val(v), arrInd(ai), valInd(vi) {}
    };

    struct Compare
    {
        bool operator()(const Element &a, const Element &b)
        {
            return a.val > b.val;
        }
    };

public:
    vector<int> mergeKSortedArrays(vector<vector<int>> &nums)
    {

        priority_queue<Element, vector<Element>, Compare> pq;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(Element(nums[i][0], i, 0));
        }
        vector<int> result;
        while (!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            result.push_back(ele.val);
            if (ele.valInd + 1 < nums[ele.arrInd].size())
            {
                pq.push(Element(nums[ele.arrInd][ele.valInd + 1], ele.arrInd, ele.valInd + 1));
            }
        }
        return result;
    }
};

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> nums;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        nums.push_back(arr);
    }

    Solution sol;
    vector<int> result = sol.mergeKSortedArrays(nums);

    for (auto &x : result)
        cout << x << " ";
    cout << "\n";

    return 0;
}