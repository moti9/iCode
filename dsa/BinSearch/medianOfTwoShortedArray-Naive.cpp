#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    double medianOfTwoShortedArray(vector<int> &arr1, int n1, vector<int> &arr2, int n2)
    {
        vector<int> arr;
        int n = n1 + n2;
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
                arr.push_back(arr1[i++]);
            else
                arr.push_back(arr2[j++]);
        }
        while (i < n1)
        {
            arr.push_back(arr1[i++]);
        }
        while (j < n2)
        {
            arr.push_back(arr2[j++]);
        }

        if (n & 1)
            return (double)arr[n / 2];
        return ((double)arr[n / 2] + (double)arr[(n / 2) - 1]) / 2.0;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    Solution sol;
    cout << sol.medianOfTwoShortedArray(arr1, n, arr2, m) << endl;

    return 0;
}