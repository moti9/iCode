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

        int leftMin[n], rightMin[n];

        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                leftMin[i] = 0;
            }
            else
            {
                leftMin[i] = st.top() + 1;
            }

            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if (st.empty())
            {
                rightMin[i] = n - 1;
            }
            else
            {
                rightMin[i] = st.top() - 1;
            }

            st.push(i);
        }

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            int currArea = (rightMin[i] - leftMin[i] + 1) * heights[i];
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