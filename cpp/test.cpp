#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int sum = 0;
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i; j <= 10; j++)
        {
            for (int k = j; k <= 10; k++)
            {
                sum += k;
                if (sum <= 5)
                    cout << sum << " ";
                else
                {
                    sum = 0;
                    return 0;
                }
            }
        }
    }

    return 0;
}