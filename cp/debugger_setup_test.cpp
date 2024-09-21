#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << "\n";
#else
#define debug(x) ;
#endif

template <typename T>
void _print(T x)
{
    cerr << x;
}

template <typename T>
void _print(vector<T> &arr)
{
    cerr << "[";
    for (T x : arr)
    {
        _print(x);
        cerr << " ";
    }
    cerr << "]";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stderr);
    freopen("output.txt", "w", stderr);
    freopen("error.txt", "w", stderr);
#endif

    srand(time(nullptr));
    int x = 10;
    int tt = rand() % 10;
    while (tt--)
    {
        x++;
        debug(x);

        int n = rand() % 11;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x = rand() % 100001;
            arr.push_back(x);
        }
        debug(arr);
    }

    return 0;
}
/*
 ___  ___     _______    ____________    _
|   \/   |   /  ___  \  |_____  _____|  | |
| |\  /| |  |  /   \  |       | |       | |
| | \/ | |  |  |   |  |       | |       | |
| |    | |  |  \___/  |       | |       | |
|_|    |_|   \_______/        |_|       |_|

*/
