#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int findThreshold(vector<int> &arr, int n, int div)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += ceil((float)arr[i] / (float)div);
        }
        return sum;
    }

public:
    int smallestDivisor(vector<int> &arr, int n, int threshold)
    {
        if (n > threshold)
            return -1;
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int sum = findThreshold(arr, n, mid);
            if (sum <= threshold)
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int threshold;
    cin >> threshold;

    Solution sol;
    cout << sol.smallestDivisor(arr, n, threshold) << endl;

    return 0;
}