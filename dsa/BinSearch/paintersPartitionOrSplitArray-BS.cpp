#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int countPainters(vector<int> &boards, int n, int time)
    {
        int cntP = 1;
        long long boardAr = 0;
        for (int i = 0; i < n; i++)
        {
            if (boardAr + boards[i] <= time)
            {
                boardAr += boards[i];
            }
            else
            {
                cntP += 1;
                boardAr = boards[i];
            }
        }
        return cntP;
    }

public:
    int findMinimumPaintTime(vector<int> &boards, int n, int m)
    {
        if (m > n)
        {
            return -1;
        }
        int low = *max_element(boards.begin(), boards.end());
        int high = accumulate(boards.begin(), boards.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int cntP = countPainters(boards, n, mid);
            if (cntP > m)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> boards(n);
    for (int i = 0; i < n; i++)
    {
        cin >> boards[i];
    }
    int k;
    cin >> k;

    Solution sol;
    cout << sol.findMinimumPaintTime(boards, n, k) << endl;

    return 0;
}