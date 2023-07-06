#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        int area = 0;

        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                {
                    width = i;
                }
                else
                {
                    width = i - st.top() - 1;
                }
                int currArea = width * height;
                area = max(area, currArea);
            }

            st.push(i);
        }

        return area;
    }

public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int area = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                {
                    heights[j] = 0;
                }
                else
                {
                    heights[j] += 1;
                }
            }
            area = max(area, largestRectangleArea(heights));
        }

        return area;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;
            matrix[i].push_back(ch);
        }
    }

    Solution sol;
    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}