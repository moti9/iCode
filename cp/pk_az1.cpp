#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007


int determineMinStorage(vector<int> appMemory, int k) {
    int n = appMemory.size();
    sort(appMemory.begin(), appMemory.end());

    if (n == k) {
        return *max_element(appMemory.begin(), appMemory.end());
    }

    if (n == 2 * k) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans = max(ans, appMemory[i] + appMemory[n - 1 - i]);
        }
        return ans;
    }

    int singleCount = 2 * k - n;
    int ans = 0;

    for (int i = 0; i < singleCount; i++) {
        ans = max(ans, appMemory[n - 1 - i]);
    }

    int left = 0, right = n - 1 - singleCount;
    while (left < right) {
        ans = max(ans, appMemory[left] + appMemory[right]);
        left++;
        right--;
    }

    return ans;
}

int main() {
    vector<int> appMemory = {9, 2, 4, 6};
    int k = 3;
    cout << determineMinStorage(appMemory, k) << endl;
    return 0;
}
