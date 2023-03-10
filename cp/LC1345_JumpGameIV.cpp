#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(n, 0);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int curr = q.front();
                q.pop();
                visited[curr]=true;
                if (curr == n - 1)
                {
                    return steps;
                }

                vector<int> &nbrs = mp[arr[curr]];
                nbrs.push_back(curr - 1);
                nbrs.push_back(curr + 1);
                for (auto nb : nbrs)
                {
                    if (nb > 0 && nb < n && !visited[nb])
                    {
                        q.push(nb);
                        visited[nb] = true;
                    }
                }
                nbrs.clear();
            }
            steps += 1;
        }
        return -1;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.minJumps(arr) << endl;

    return 0;
}