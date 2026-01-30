#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007
#define endl "\n"
#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll increments = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            increments += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }

    cout << increments << endl;

    return 0;
}