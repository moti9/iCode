#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

     *
    ***
   *****
  *******
 *********
***********

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 1; i <= n; i++)
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

/*
class Solution
{
public:
    void printTriangle(int n)
    {
        int col = 2 * n - 1;
        for (int i = 1; i <= n; i++)
        {
            int star = 2 * i - 1;
            int space = (col - star) / 2;
            while (space--)
            {
                cout << " ";
            }
            while (star--)
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