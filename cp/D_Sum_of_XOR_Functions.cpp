#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> prefixXOR(n + 1), suffixXOR(n + 1);
    ll xor_all = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        xor_all ^= arr[i];
    }

    prefixXOR[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    }

    suffixXOR[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixXOR[i] = suffixXOR[i + 1] ^ arr[i];
    }

    const int MOD = 998244353;
    long long result = 0;

    for (int l = 0; l < n; l++)
    {
        int xor_result = 0;
        for (int r = l; r < n; r++)
        {
            int prefix = (l > 0) ? prefixXOR[l - 1] : 0;
            int suffix = (r < n - 1) ? suffixXOR[r + 1] : 0;
            xor_result = (prefix ^ xor_all ^ suffix);
            result += (r - l + 1) * 1LL * xor_result;
            result %= MOD;
        }
    }

    cout << result << endl;

    return 0;
}
