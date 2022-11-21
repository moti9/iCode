#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int arr[] = {1, 4, 5, 8, 9, 10, 63};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << binary_search(arr, arr + n, 9) << endl;
    // Return true if present otherwise return false

    return 0;
}