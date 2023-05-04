#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int addDigits(int num)
    {
        int ans = 0;
        while (true)
        {

            string n = to_string(num);
            if (n.length() == 1)
            {
                break;
            }
            num = 0;
            for (int i = 0; i < n.length(); i++)
            {
                num += (n[i] - '0');
            }
        }
        return num;
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    cout << sol.addDigits(n) << endl;

    return 0;
}