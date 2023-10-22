#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findRequiredDays(vector<int> &weights, int n, int capacity)
    {
        int day = 1;
        int load = 0;
        for (int i = 0; i < n; i++)
        {
            if (load + weights[i] > capacity)
            {
                day += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return day;
    }

public:
    int findLeastCapacity(vector<int> &weights, int n, int day)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int req_day = findRequiredDays(weights, n, mid);
            if (req_day <= day)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int day;
    cin >> day;

    Solution sol;
    cout << sol.findLeastCapacity(weights, n, day) << endl;

    return 0;
}