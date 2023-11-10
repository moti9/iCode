#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> mp;
    float result = 0;
    for (int i = 1; i <= 100; i++)
    {
        // int x;
        // cin >> x;
        // mp[x]++;
        // if (mp[x] == 1)
        // {
        //     result += pow(2, x);
        // }
        result += pow(2, i);
    }
    cout << pow(2, -2) << endl;

    cout << result << endl;

    return 0;
}