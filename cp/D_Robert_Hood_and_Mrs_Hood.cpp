#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Event
{
    int position;
    bool isStart;
};

bool eventComparator(const Event &a, const Event &b)
{
    if (a.position == b.position)
    {
        return a.isStart && !b.isStart;
    }
    return a.position < b.position;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n, d, k;
        cin >> n >> d >> k;

        vector<Event> events;
        for (int i = 0; i < k; i++)
        {
            int l, r;
            cin >> l >> r;
            events.push_back({l, true});
            events.push_back({r + 1, false});
        }

        sort(events.begin(), events.end(), eventComparator);

        vector<int> overlaps(n + 1, 0);
        int activeIntervals = 0;
        int lastPosition = 1;

        for (const auto &event : events)
        {
            for (int i = lastPosition; i < event.position && i <= n; ++i)
            {
                overlaps[i] = activeIntervals;
            }

            if (event.isStart)
            {
                activeIntervals++;
            }
            else
            {
                activeIntervals--;
            }

            lastPosition = event.position;
        }

        for (int i = lastPosition; i <= n; ++i)
        {
            overlaps[i] = activeIntervals;
        }

        int maxOverlap = -1, bestStart1 = -1;
        for (int i = 1; i <= n - d + 1; ++i)
        {
            int currentOverlap = 0;
            for (int j = i; j < i + d; ++j)
            {
                currentOverlap += overlaps[j];
            }
            if (currentOverlap > maxOverlap)
            {
                maxOverlap = currentOverlap;
                bestStart1 = i;
            }
        }

        int minOverlap = INT_MAX, bestStart2 = -1;
        for (int i = 1; i <= n - d + 1; ++i)
        {
            int currentOverlap = 0;
            for (int j = i; j < i + d; ++j)
            {
                currentOverlap += overlaps[j];
            }
            if (currentOverlap < minOverlap || (currentOverlap == minOverlap && bestStart2 == -1))
            {
                minOverlap = currentOverlap;
                bestStart2 = i;
            }
        }

        cout << bestStart1 << " " << bestStart2 << "\n";
    }

    return 0;
}

/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/