#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int reverse(int x)
    {
        string str = to_string(x);

        std::reverse(str.begin(), str.end());

        bool isNegative = false;
        if (str.back() == '-')
        {
            isNegative = true;
            str.pop_back();
        }

        long long reversed = stoll(str);
        if (isNegative)
            reversed = -reversed;

        if (reversed < INT_MIN || reversed > INT_MAX)
            return 0;

        return static_cast<int>(reversed);
    }
};

int main()
{
    int n;
    cin >> n;

    Solution sol;
    cout << sol.reverse(n) << endl;

    return 0;
}