#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int barn_x, barn_y;
    int lake_x, lake_y;
    int rock_x, rock_y;
    for(int i = 0; i < 10; i++) {
        string row;
        cin >> row;

        for(int j = 0; j < 10; j++) {
            char cell = row[j];
            if(cell == 'B') {
                barn_x = i;
                barn_y = j;
            } else if(cell == 'L') {
                lake_x = i;
                lake_y = j;
            } else if(cell == 'R') {
                rock_x = i;
                rock_y = j;
            }
        }
    }

    int distance = abs(barn_x - lake_x) + abs(barn_y - lake_y) - 1;
    if((barn_x == lake_x && barn_x == rock_x &&
        ((lake_y < rock_y && rock_y < barn_y) || (barn_y < rock_y && rock_y < lake_y))) ||
       (barn_y == lake_y && barn_y == rock_y &&
        ((lake_x < rock_x && rock_x < barn_x) || (barn_x < rock_x && rock_x < lake_x)))) {
        distance += 2;
    }

    cout << distance << "\n";

    return 0;
}