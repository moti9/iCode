#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int maxRequest(int ind, int n, vector<vector<int>> &requests, vector<int> &indegree)
    {

        if (ind < 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (indegree[i] != 0)
                {
                    return -1e9;
                }
            }
            return 0;
        }
        int maxReq = maxRequest(ind - 1, n, requests, indegree);

        indegree[requests[ind][0]]--;
        indegree[requests[ind][1]]++;

        maxReq = max(maxReq, 1 + maxRequest(ind - 1, n, requests, indegree));

        indegree[requests[ind][0]]++;
        indegree[requests[ind][1]]--;

        return maxReq;
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<int> indegree(n, 0);
        int m = requests.size();
        return maxRequest(m - 1, n, requests, indegree);
    }
};

/*
class Solution
{
public:
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        int m = requests.size();

        int answer = 0;

        for (int mask = 0; mask < (1 << m); mask++)
        {
            vector<int> indegree(n, 0);
            int pos = m - 1;

            int bitCount = __builtin_popcount(mask);

            if (bitCount <= answer)
            {
                continue;
            }

            for (int curr = mask; curr > 0; curr >>= 1, pos--)
            {
                if (curr & 1)
                {
                    indegree[requests[pos][0]]--;
                    indegree[requests[pos][1]]++;
                }
            }

            int flag = 1;

            for (int i = 0; i < n; i++)
            {
                if (indegree[i])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
            {
                answer = bitCount;
            }
        }

        return answer;
    }
};
*/

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    vector<vector<int>> requests;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;

        requests.push_back({from, to});
    }

    Solution sol;
    cout << sol.maximumRequests(n, requests) << endl;

    return 0;
}