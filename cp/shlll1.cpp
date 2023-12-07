#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largestLand(vector<vector<int>> houses) {
    int n = houses.size();

    vector<int> position;
    for (int i = 0; i < n; ++i) {
        position.push_back(houses[i][1]);
    }

    // Sort houses based on their position
    sort(position.begin(), position.end());

    int x1, x2;
    int position1, position2;
    int maxGap = 0;

    // Iterate through the sorted positions to find the largest gap
    for (int i = 0; i < n - 1; ++i) {
        int gap = position[i + 1] - position[i] - 1;

        if (gap > maxGap) {
            maxGap = gap;
            x1 = position[i];
            x2 = position[i + 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        if (x1 == houses[i][1]) {
            position1 = i;
        } else if (x2 == houses[i][1]) {
            position2 = i;
        }
    }

    vector<int> result;
    if (houses[position1][0] > houses[position2][0]) {
        result = {houses[position2][0], houses[position1][0]};
    } else {
        result = {houses[position1][0], houses[position2][0]};
    }

    return result;
}

int main() {
    int houses_row;
    int houses_col;
    cin >> houses_row;
    cin >> houses_col;

    vector<vector<int>> houses;

    for (int idx = 0; idx < houses_row; idx++) {
        vector<int> temp_vector;
        for (int jdx = 0; jdx < houses_col; jdx++) {
            int temp;
            cin >> temp;
            temp_vector.push_back(temp);
        }
        houses.push_back(temp_vector);
    }

    vector<int> result = largestLand(houses);

    // Output the result
    cout << "Result: [" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}
