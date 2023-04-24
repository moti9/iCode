#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Greedy
int FindmaxArea(vector<int> &height)
{
    int ans = 0;
    int n = height.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int h = min(height[i], height[j]);
            int w = j - i;
            int ar = h * w;
            ans = max(ans, ar);
        }
    }
    return ans;
}

// Optimized
int maxArea(vector<int> &height)
{
    int ans = 0;
    int left = 0, right = height.size() - 1;
    while (left < right)
    {
        int h = min(height[left], height[right]);
        int w = right - left;
        int area = h * w;
        ans = max(ans, area);

        if (height[left] < height[right])
        {
            left++;
        }
        else if (height[left] == height[right])
        {
            left++;
            right--;
        }
        else
        {
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return 0;
}