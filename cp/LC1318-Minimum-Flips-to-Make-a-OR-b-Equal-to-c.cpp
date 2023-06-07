#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int cnt = 0;
        while (a != 0 | b != 0 | c != 0)
        {
            if ((c & 1) == 1)
            {
                if (((a & 1) == 0) && ((b & 1) == 0))
                {
                    cnt += 1;
                }
            }
            else
            {
                cnt += ((a & 1) + (b & 1));
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return cnt;
    }
};

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    Solution sol;
    cout << sol.minFlips(a, b, c) << endl;

    return 0;
}