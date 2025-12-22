#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int positive_value(int arr[], int n) 
    {
        int smallest_value = -1;

        sort(arr, arr + n);

        int res = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] <= res) {
                res += arr[i];
            } else {
                break;
            }
        }

        smallest_value = res;
        return smallest_value;
    }
};

int main() {
    Solution sol;

    int arr[] = {11, 3, 5, 72, 12, 5, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int arr2[] = {2, 13, 5, 12, 5, 5, 2, 12, 7, 1};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Smallest positive value not present as sum: " << sol.positive_value(arr, n) << endl;
    cout << "Smallest positive value not present as sum: " << sol.positive_value(arr2, n2) << endl;

    return 0;
}
