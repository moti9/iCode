#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int area = 0;

        for (int i = 0; i < n; i++)
        {
            int minHeight = heights[i];
            for (int j = i; j < n; j++)
            {
                minHeight = min(minHeight, heights[j]);

                int width = j - i + 1;
                int currArea = minHeight * width;
                area = max(area, currArea);
            }
        }

        return area;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    Solution sol;
    cout << sol.largestRectangleArea(heights) << endl;

    return 0;
}