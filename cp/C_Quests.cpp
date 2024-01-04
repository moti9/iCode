#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Quest
{
    int a, b;

    // bool operator<(const Quest& other) const {
    //     return a - b > other.a - other.b;
    // }
};

void solvehere()
{
    int n, k;
    cin >> n >> k;

    vector<Quest> quests(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> quests[i].a;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> quests[i].b;
    }

    // sort(quests.begin(), quests.end());

    long long totalExp = 0;
    long long exp = 0, bmax = 0;

    for (int i = 0; i < n; ++i)
    {
        if (k == i)
            break;
        exp += quests[i].a;
        bmax = max(bmax, (long long)quests[i].b);
        totalExp = max(totalExp, exp + (k - i - 1) * bmax);
    }

    cout << totalExp << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ttt;
    cin >> ttt;

    while (ttt--)
    {
        solvehere();
    }

    return 0;
}
