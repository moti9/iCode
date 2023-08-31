#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j)
    {
        while (i < high && arr[i] <= pivot)
        {
            i += 1;
        }
        while (j > low && arr[j] > pivot)
        {
            j -= 1;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

vector<int> quickSort(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
    return arr;
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

    vector<int> sortedArr = quickSort(arr, 0, n - 1);
    for (auto &sa : sortedArr)
    {
        cout << sa << " ";
    }
    cout << endl;

    return 0;
}