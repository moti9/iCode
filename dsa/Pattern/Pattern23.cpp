#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

******
*    *
*    *
*    *
*    *
******

*/

class Solution
{
public:
    void printSquare(int n)
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 || i == n || j == 1 || j == n)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
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
        ob.printSquare(n);
    }
    return 0;
}