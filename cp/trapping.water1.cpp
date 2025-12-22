#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007


class Solution {
    int getTrappedWater(vector<int> &h, int index, int n) {
        int maxLeft = 0, maxRight = 0;

        for (int i = 0; i < index; i++)
            maxLeft = max(maxLeft, h[i]);

        for (int i = index + 1; i < n; i++)
            maxRight = max(maxRight, h[i]);

        int water = min(maxLeft, maxRight) - h[index];
        return water > 0 ? water : 0;
    }
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += getTrappedWater(height, i, n);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution sol;
    cout << sol.trap(height) << "\n";
    

    return 0;
}