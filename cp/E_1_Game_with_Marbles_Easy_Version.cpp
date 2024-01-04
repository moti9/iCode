#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> alice(n), bob(n);

        for (int i = 0; i < n; ++i) {
            cin >> alice[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> bob[i];
        }

        // Sort the marbles in descending order for both Alice and Bob
        sort(alice.rbegin(), alice.rend());
        sort(bob.rbegin(), bob.rend());

        int aliceScore = 0, bobScore = 0;
        bool aliceTurn = true;

        for (int i = 0; i < n; ++i) {
            if (aliceTurn) {
                // Alice's turn, choose the maximum color for Alice and discard all for Bob
                aliceScore += alice[i];
            } else {
                // Bob's turn, discard all marbles of the chosen color for both players
                bobScore += bob[i];
            }

            aliceTurn = !aliceTurn;
        }

        int result = aliceScore - bobScore;
        cout << result << endl;
    }

    return 0;
}
