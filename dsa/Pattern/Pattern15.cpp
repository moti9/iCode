#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21

*/

class Solution
{
public:
    void printTriangle(int n)
    {
        int num = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << num++ << " ";
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
