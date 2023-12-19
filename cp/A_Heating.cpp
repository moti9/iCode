#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int ci, sumi;
        cin >> ci >> sumi;

        int minCost = 0;

        // Calculate the minimum cost based on the optimization
        if (sumi % ci == 0) {
            int equalSections = sumi / ci;
            minCost = ci * equalSections * equalSections;
        } else {
            int equalSections = sumi / ci;
            int remainingRadiators = ci - (sumi % ci);

            minCost = remainingRadiators * equalSections * equalSections +
                      (ci - remainingRadiators) * (equalSections + 1) * (equalSections + 1);
        }

        cout << minCost << endl;
    }

    return 0;
}
