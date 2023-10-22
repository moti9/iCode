#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    double medianOfTwoShortedArray(vector<int> &arr1, int n1, vector<int> &arr2, int n2)
    {
        int n = n1 + n2;
        int i = 0, j = 0;
        int ind2 = n / 2;
        int ind1 = ind2 - 1;
        int ele1 = -1, ele2 = -1;
        int cnt = 0;
        while (i < n1 && j < n2)
        {
            if (arr1[i] <= arr2[j])
            {
                if (cnt == ind1)
                    ele1 = arr1[i];
                if (cnt == ind2)
                    ele2 = arr1[i];
                cnt += 1;
                i += 1;
            }
            else
            {
                if (cnt == ind1)
                    ele1 = arr2[j];
                if (cnt == ind2)
                    ele2 = arr2[j];
                cnt += 1;
                j += 1;
            }
        }
        while (i < n1)
        {
            if (cnt == ind1)
                ele1 = arr1[i];
            if (cnt == ind2)
                ele2 = arr1[i];
            cnt += 1;
            i += 1;
        }
        while (j < n2)
        {
            if (cnt == ind1)
                ele1 = arr2[j];
            if (cnt == ind2)
                ele2 = arr2[j];
            cnt += 1;
            j += 1;
        }
        if (n & 1)
            return ele1;
        return ((double)ele1 + (double)ele2) / 2.0;
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