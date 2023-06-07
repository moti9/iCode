#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Using Modification in given array(It's not good practice to modify the given data)
// TC- O(N)
// SC- O(1)

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        int a0 = *min_element(arr.begin(), arr.end());
        int an = *max_element(arr.begin(), arr.end());
        int n = arr.size();

        if ((an - a0) % (n - 1))
        {
            return false;
        }
        int diff = (an - a0) / (n - 1);
        int i = 0;
        while (i < n)
        {
            if (arr[i] == a0 + i * diff)
            {
                i += 1;
            }
            else if ((arr[i] - a0) % diff)
            {
                return false;
            }
            else
            {
                int j = (arr[i] - a0) / diff;
                if (arr[i] == arr[j])
                {
                    return false;
                }
                swap(arr[i], arr[j]);
            }
        }
        return true;
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
    cout << sol.canMakeArithmeticProgression(arr) << endl;

    return 0;
}