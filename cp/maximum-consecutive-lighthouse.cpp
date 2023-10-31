#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int maxConsecutiveLighthouses(vector<int> &positions)
{
    sort(positions.begin(), positions.end());
    int n = positions.size();
    int cnt = 1;
    int maxCnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (positions[i] - positions[i - 1] <= 1)
        {
            cnt++;
        }
        else
        {
            maxCnt = max(maxCnt, cnt);
            cnt = 1;
        }
    }

    maxCnt = max(maxCnt, cnt);
    return maxCnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> positions(n);
    for (int i = 0; i < n; i++)
    {
        cin >> positions[i];
    }

    cout << maxConsecutiveLighthouses(positions) << endl;

    return 0;
}
