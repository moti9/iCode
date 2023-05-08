#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(NlogN)
// SC- O(1)

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
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
    Solution sol;
    sol.sortColors(arr);

    for (auto a : arr)
        cout << a << " ";
    cout << endl;

    return 0;
}