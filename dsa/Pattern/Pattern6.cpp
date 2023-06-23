#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

1 2 3 4 5 6
1 2 3 4 5
1 2 3 4
1 2 3
1 2
1

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = 1; j <= i; j++)
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
// } Driver Code Ends