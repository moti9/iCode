#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> pg(7);
    for (int i = 0; i < 7; i++)
    {
        cin >> pg[i];
    }
    int temp = n;
    while (temp > 0)
    {
        for (int i = 0; i < 7; i++)
        {
            if (temp > pg[i])
            {
                temp -= pg[i];
            }
            else
            {
                cout << i + 1;
                temp -= pg[i];
                break;
            }
        }
    }

    return 0;
}