#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA
ABCDEFEDCBA

*/

class Solution
{
public:
    void printTriangle(int n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n - i; j++)
            {
                cout << " ";
            }
            for (char j = 'A'; j <= 'A' + i; j++)
            {
                cout << j;
            }
            for (char j = 'A' + i - 1; j >= 'A'; j--)
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