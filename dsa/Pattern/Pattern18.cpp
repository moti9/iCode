#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

A
BB
CCC
DDDD
EEEEE
FFFFFF

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 0; i < n; i++)
        {
            char ch = 'A' + i;
            for (int j = 0; j <= i; j++)
            {
                cout << ch;
            }
            cout << endl;
        }
    }
};

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