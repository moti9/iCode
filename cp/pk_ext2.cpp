#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution2 {
public:
    int find_max_tip(vector<int> ai, vector<int> bi, int no_of_integers, int X, int Y) {
        struct Order {
            int a, b, diff;
        };

        vector<Order> orders;
        for (int i = 0; i < no_of_integers; i++) {
            orders.push_back({ai[i], bi[i], abs(ai[i] - bi[i])});
        }

        sort(orders.begin(), orders.end(), [](const Order& o1, const Order& o2) {
            return o1.diff > o2.diff;
        });

        int calculated_tip = 0;

        for (int i = 0; i < no_of_integers; i++) {
            if ((orders[i].a >= orders[i].b && X > 0) || Y == 0) {
                calculated_tip += orders[i].a;
                X--;
            } else {
                calculated_tip += orders[i].b;
                Y--;
            }
        }

        return calculated_tip;
    }
};


class Solution {
public:
    int find_max_tip(vector<int> ai, vector<int> bi, int no_of_integers, int X, int Y) {
        vector<pair<int, int>> diff_index;
        for (int i = 0; i < no_of_integers; i++) {
            diff_index.push_back({abs(ai[i] - bi[i]), i});
        }

        sort(diff_index.rbegin(), diff_index.rend());

        int total_tip = 0;
        int adam_orders = 0, mathew_orders = 0;

        for (auto &p : diff_index) {
            int i = p.second;

            if (ai[i] >= bi[i]) {
                if (adam_orders < X) {
                    total_tip += ai[i];
                    adam_orders++;
                } else if (mathew_orders < Y) {
                    total_tip += bi[i];
                    mathew_orders++;
                }
            } else {
                if (mathew_orders < Y) {
                    total_tip += bi[i];
                    mathew_orders++;
                } else if (adam_orders < X) {
                    total_tip += ai[i];
                    adam_orders++;
                }
            }
        }

        return total_tip;
    }
};

int main() {
    Solution sol;
    Solution2 sol2;

    vector<int> ai = {1, 2, 3, 4, 5};
    vector<int> bi = {5, 4, 3, 2, 1};
    int N = 5, X = 1, Y = 3;
    // vector<int> ai = {4, 6, 3, 7, 2, 4};
    // vector<int> bi = {5, 3, 4, 2, 3, 7};
    // int N = 6;
    // int X = 4;
    // int Y = 3;

    int max_tip = sol.find_max_tip(ai, bi, N, X, Y);
    cout << "Maximum Tip: " << max_tip << endl;

    int max_tip2 = sol2.find_max_tip(ai, bi, N, X, Y);
    cout << "Maximum Tip (Solution2): " << max_tip2 << endl;

    return 0;
}
