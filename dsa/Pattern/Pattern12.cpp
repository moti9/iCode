#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

*
**
***
****
*****
******
*****
****
***
**
*

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            int stars = i;
            if (i > n)
            {
                stars = 2 * n - stars;
            }
            for (int j = 1; j <= stars; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};

/*
class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
    }
};
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}