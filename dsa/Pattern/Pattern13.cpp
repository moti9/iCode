#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
0 1 0 1 0 1

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        int start = 1;
        for (int i = 1; i <= n; i++)
        {
            start = (i & 1) ? 1 : 0;
            for (int j = 1; j <= i; j++)
            {
                cout << start << " ";
                start = 1 - start;
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
