#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int> &triple1, const vector<int> &triple2)
{
    int diffCount = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (triple1[i] != triple2[i])
        {
            ++diffCount;
        }
    }
    return (diffCount == 1);
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        // vector<vector<int>> tp;

        // for (int i = 0; i < n - 2; i++)
        //     tp.push_back({arr[i], arr[i + 1], arr[i + 2]});

        long ans = 0;
        for (int i = 0; i < n - 3; i++)
        {
            int diffCount = 0;

            if (arr[i] != arr[i + 1])
            {
                ++diffCount;
            }
            if (arr[i + 1] != arr[i + 2])
            {
                ++diffCount;
            }
            if (arr[i + 2] != arr[i + 3])
            {
                ++diffCount;
            }

            if (diffCount == 1)
                ans += 1;
        }
        // for (int i = 0; i < tp.size(); i++)
        // {
        //     for (int j = i + 1; j < tp.size(); j++)
        //     {
        //         if (check(tp[i], tp[j]))
        //         {
        //             ans += 1;
        //         }
        //     }
        // }
        cout << ans << '\n';
    }

    return 0;
}