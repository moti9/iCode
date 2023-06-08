
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int mod = 100000;

public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        queue<pair<int, int>> q;
        q.push({0, start});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;

        while (!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();

            for (auto a : arr)
            {
                int num = (a * node) % mod;
                if (num == end)
                {
                    return steps + 1;
                }
                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;
                    q.push({dist[num], num});
                }
            }
        }
        return -1;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}
