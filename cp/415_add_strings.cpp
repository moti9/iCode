#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int n = num1.length();
        int m = num2.length();
        if (n < m)
        {
            return addStrings(num2, num1);
        }

        int carry = 0, ind = 0;
        while (ind < n || ind < m)
        {
            if ((ind >= n || ind >= m) && carry == 0)
                break;

            int ni = n - ind - 1;
            int mi = m - ind - 1;

            int n1 = (ni >= 0) ? num1[ni] - '0' : 0;
            int n2 = (mi >= 0) ? num2[mi] - '0' : 0;
            int sum = n1 + n2 + carry;
            int fn = sum % 10;
            carry = sum / 10;

            num1[ni] = fn + '0';

            ind += 1;
        }

        if (carry)
        {
            return static_cast<char>(carry + '0') + num1;
        }

        return num1;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string num1, num2;
    cin >> num1;
    cin >> num2;

    cout << Solution().addStrings(num1, num2) << endl;

    return 0;
}