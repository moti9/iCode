#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left, right;
        int i = 0;
        int j = n - 1;
        int cnt = 0;
        while (i <= j && cnt < candidates)
        {
            left.push(costs[i]);
            i += 1;
            cnt += 1;
        }
        cnt = 0;
        while (j >= i && cnt < candidates)
        {
            right.push(costs[j]);
            j -= 1;
            cnt += 1;
        }

        long long ans = 0;
        cnt = 0;
        while (cnt < k && (!left.empty() || !right.empty()))
        {
            int left_cost = 1e6 + 6, right_cost = 1e6;
            if (!left.empty())
            {
                left_cost = left.top();
            }
            if (!right.empty())
            {
                right_cost = right.top();
            }
            if (left_cost <= right_cost)
            {
                ans += (long long)left_cost;
                left.pop();
                if (i <= j)
                {
                    if (costs[i] <= costs[j])
                    {
                        left.push(costs[i]);
                        i += 1;
                    }
                    else
                    {
                        left.push(costs[j]);
                        j -= 1;
                    }
                }
            }
            else
            {
                ans += (long long)right_cost;
                right.pop();
                if (i <= j)
                {
                    if (costs[j] < costs[i])
                    {
                        right.push(costs[j]);
                        j -= 1;
                    }
                    else
                    {
                        right.push(costs[i]);
                        i += 1;
                    }
                }
            }
            cnt += 1;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> costs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i];
    }

    int k, candidates;
    cin >> k >> candidates;

    Solution sol;
    cout << sol.totalCost(costs, k, candidates) << endl;

    return 0;
}