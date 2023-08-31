#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int maxi = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxi = j;
            }
        }
        swap(arr[i], arr[maxi]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionSort(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}