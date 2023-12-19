#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        int n = s.size();
        vector<int> cost(n, 0);

        // Iterate through the string
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // Calculate cost to move '1' to the right
                int right = i;
                while (right < n && s[right] == '1') {
                    right++;
                }

                // Update cost
                for (int j = i; j < right; j++) {
                    cost[j] = right - i;
                }

                i = right - 1; // Move i to the rightmost '1'
            }
        }

        // Calculate the total cost
        int totalCost = 0;
        for (int c : cost) {
            totalCost += c;
        }

        cout << totalCost << endl;
    }

    return 0;
}
