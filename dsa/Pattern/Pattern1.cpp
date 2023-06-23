#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *
* * * * * *

*/

class Solution
{
public:
    void printSquare(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "* ";
            }
            cout << "\n";
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
        ob.printSquare(n);
    }
    return 0;
}
