#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void generate(int i, int n, int arr[])
{
    if (i == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    arr[i] = 0;
    generate(i + 1, n, arr);
    arr[i] = 1;
    generate(i + 1, n, arr);
}

void generateStr(int n)
{
    int arr[n];
    generate(0, n, arr);
}

int main()
{
    int n;
    cin >> n;
    generateStr(n);

    return 0;
}