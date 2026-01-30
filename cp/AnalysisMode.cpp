#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define ll long long

int main() {
    // freopen("analysis_mode.in", "r", stdin);
    // freopen("analysis_mode.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> nums(7);
    for(int i = 0; i < 7; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    cout << nums[0] << " " << nums[1] << " " << (nums[6] - (nums[0] + nums[1])) << "\n";


    return 0;
}