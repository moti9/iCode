#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        list<int> lst(arr.begin(), arr.end());

        int cnt = 0;
        int maxNum = *max_element(arr.begin(), arr.end());

        if (k >= arr.size() - 1)
        {
            return maxNum;
        }

        while (true)
        {
            if (*lst.begin() < *(next(lst.begin())))
            {
                lst.push_back(*lst.begin());
                lst.pop_front();
                cnt = 1;
            }
            else
            {
                int mini = *(next(lst.begin()));
                int maxi = *lst.begin();
                lst.pop_front();
                lst.pop_front();
                lst.push_front(maxi);
                lst.push_back(mini);
                cnt++;
            }

            if (cnt >= k)
                return *lst.begin();
        }

        return cnt;
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

    int k;
    cin >> k;

    Solution sol;
    cout << sol.getWinner(arr, k) << endl;

    return 0;
}