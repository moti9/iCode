#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

***********
 *********
  *******
   *****
    ***
     *

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= n - i; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= 2 * i - 1; j++)
            {
                cout << "*";
            }
            // for (int j = 1; j <= n - i; j++)
            // {
            //     cout << " ";
            // }
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