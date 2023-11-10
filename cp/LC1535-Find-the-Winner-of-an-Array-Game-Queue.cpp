#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        int maxi = arr[0];

        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }

        int cnt = 0;
        int start = arr[0];

        for (int i = 1; i < n; i++)
        {
            int opt = arr[i];
            if (start > opt)
            {
                cnt += 1;
            }
            else
            {
                cnt = 1;
                start = opt;
            }

            if (cnt == k || start == maxi)
                return start;
        }

        return -1;
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

    int k;
    cin >> k;

    Solution sol;
    cout << sol.getWinner(arr, k) << endl;

    return 0;
}