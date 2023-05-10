#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll merge(vector<ll> &arr, vector<ll> &temp, ll low, ll mid, ll high)
{
    ll count = 0;
    ll i = low;
    ll j = mid;
    ll k = low;
    while (i < mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count = count + (mid - i);
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

ll mergeSort(vector<ll> &arr, vector<ll> &temp, ll low, ll high)
{
    ll count = 0;
    if (low < high)
    {
        ll mid = (low + high) / 2;
        count += mergeSort(arr, temp, low, mid);
        count += mergeSort(arr, temp, mid + 1, high);

        count += merge(arr, temp, low, mid + 1, high);
    }
    return count;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> temp(n);
    ll ans = mergeSort(arr, temp, 0, n - 1);
    cout << "The total inversions are " << ans << endl;

    return 0;
}