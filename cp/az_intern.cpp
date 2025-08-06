
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;


vector<int> medians(vector<int> values, int k) {
    sort(values.begin(), values.end());

    vector<int> smallest_k(values.begin(), values.begin() + k);
    vector<int> largest_k(values.end() - k, values.end());

    sort(smallest_k.begin(), smallest_k.end());
    sort(largest_k.begin(), largest_k.end());

    double min_median, max_median;

    if (k % 2 == 1) {
        min_median = smallest_k[k / 2];
        max_median = largest_k[k / 2];
    } else {
        min_median = (smallest_k[k / 2 - 1] + smallest_k[k / 2]) / 2.0;
        max_median = (largest_k[k / 2 - 1] + largest_k[k / 2]) / 2.0;
    }

    return {static_cast<int>(max_median), static_cast<int>(min_median)};
}


int main() {
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0; i<n; i++){
        cin>>values[i];
    }
    int k;
    cin>>k;
    vector<int> result = medians(values, k);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
