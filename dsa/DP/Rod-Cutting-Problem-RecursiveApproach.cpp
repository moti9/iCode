#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// TC- O(2^N)
// SC- O(N)

class Solution
{
    int maxPrice(int ind, int len, vector<int> &price)
    {
        if (ind == 0)
        {
            return (len / (ind + 1)) * price[ind];
        }

        int notCut = maxPrice(ind - 1, len, price);
        int cut = 0;
        if (ind + 1 <= len)
        {
            cut = price[ind] + maxPrice(ind, len - ind - 1, price);
        }
        return max(cut, notCut);
    }

public:
    int cutRod(vector<int> &price, int n)
    {
        return maxPrice(n - 1, n, price);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    Solution sol;
    cout << sol.cutRod(price, n) << endl;

    return 0;
}