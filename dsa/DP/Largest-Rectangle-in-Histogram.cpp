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
            int left = i, right = i;

            while (left > 0 && heights[left - 1] >= heights[i])
            {
                left--;
            }

            while (right < n - 1 && heights[right + 1] >= heights[i])
            {
                right++;
            }

            int width = right - left + 1;
            int currArea = heights[i] * width;
            area = max(area, currArea);
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