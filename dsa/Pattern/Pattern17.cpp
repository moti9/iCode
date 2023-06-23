#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
ABCDEF
ABCDE
ABCD
ABC
AB
A
*/


class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (char j = 'A'; j <= 'A' + i; j++)
            {
                cout << j;
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