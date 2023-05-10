#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// class Solution
// {
// public:
//     vector<int> colorTheArray(int n, vector<vector<int>> &queries)
//     {
//         int m = queries.size();
//         std::vector<int> ans(m);
//         std::vector<int> nums(n, 0);

//         for (int i = 0; i < m; i++)
//         {
//             int idx = queries[i][0];
//             int color = queries[i][1];

//             int left = (idx > 0) ? nums[idx - 1] : 0;
//             int right = (idx < n - 1) ? nums[idx + 1] : 0;

//             if (left == color && right == color)
//             {
//                 ans[idx] = ans[idx - 1] + ans[idx + 1] + 2;
//             }
//             else if (left == color)
//             {
//                 ans[idx] = ans[idx - 1] + 1;
//             }
//             else if (right == color)
//             {
//                 ans[idx] = ans[idx + 1] + 1;
//             }
//             else
//             {
//                 ans[idx] = 1;
//             }

//             nums[idx] = color;
//         }

//         return ans;
//     }
// };

#include <vector>

class Solution
{
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &queries)
    {
        int m = queries.size();
        std::vector<int> ans(m);
        std::vector<int> nums(n);

        for (int i = 0; i < m; i++)
        {
            int idx = queries[i][0];
            int color = queries[i][1];

            int left = (idx > 0) ? nums[idx - 1] : 0;
            int right = (idx < n - 1) ? nums[idx + 1] : 0;

            if (left == color && right == color)
            {
                ans[idx] = ans[idx - 1] + ans[idx + 1] + 1;
            }
            else if (left == color || right == color)
            {
                if (left == color)
                {
                    ans[idx] = ans[idx - 1] + 1;
                }
                if (right == color)
                {
                    ans[idx] = ans[idx + 1] + 1;
                }
            }
            else
            {
                ans[i] = 1;
            }

            nums[idx] = color;
        }

        return ans;
    }
};

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    Solution sol;
    vector<int> ans = sol.colorTheArray(n, queries);
    for (auto a : ans)
        cout << a << " ";
    cout << endl;

    return 0;
}