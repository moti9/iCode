#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high)
        {
            const int m = (low + high) / 2;
            if (shipDays(weights, m) <= days)
                high = m;
            else
                low = m + 1;
        }

        return low;
    }

private:
    int shipDays(const vector<int> &weights, int shipCapacity)
    {
        int days = 1;
        int capacity = 0;
        for (const int weight : weights)
        {
            if (capacity + weight > shipCapacity)
            {
                ++days;
                capacity = weight;
            }
            else
            {
                capacity += weight;
            }
        }
        return days;
    };
};

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    int days;
    cin >> days;
    Solution sol;
    cout << sol.shipWithinDays(weight, days) << endl;

    return 0;
}