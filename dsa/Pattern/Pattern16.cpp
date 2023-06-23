#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
A
AB
ABC
ABCD
ABCDE
ABCDEF
*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (char j = 'A'; j <= 'A' + i; j++)
            {
                cout << j;
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
            for (int j = 0; j < i; j++)
            {
                cout << (char)(j + 'A');
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