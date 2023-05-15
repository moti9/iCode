#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {
        int cnt = 0;
        for (auto s : details)
        {
            string age = s.substr(11, 2);
            int a = stoi(age);
            if (a > 60)
                cnt += 1;
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> details(n);
    for (int i = 0; i < n; i++)
    {
        cin >> details[i];
    }

    Solution sol;
    cout << sol.countSeniors(details) << endl;

    return 0;
}