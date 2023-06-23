#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

1                     1
1 2                 2 1
1 2 3             3 2 1
1 2 3 4         4 3 2 1
1 2 3 4 5     5 4 3 2 1
1 2 3 4 5 6 6 5 4 3 2 1

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
            for (int j = 1; j <= (n - i) * 2; j++)
            {
                cout << " ";
            }
            for (int j = 1; j <= (n - i) * 2; j++)
            {
                cout << " ";
            }
            for (int j = i; j >= 1; j--)
            {
                cout << j << " ";
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
