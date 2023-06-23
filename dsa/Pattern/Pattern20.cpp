#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

F
F E
F E D
F E D C
F E D C B
F E D C B A

*/

class Solution
{
public:
    void printTriangle(int n)
    {

        for (int i = 0; i < n; i++)
        {
            char ch = 'A' + n - 1;
            for (char j = 0; j <= i; j++)
            {
                cout << ch-- << " ";
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

        for (int i = 0; i < n; i++)
        {
            for (char j = 'A' + n - 1; j >= 'A' + n - i - 1; j--)
            {
                cout << j << " ";
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