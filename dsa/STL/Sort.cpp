#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*
# Uses a mix of quicksort and mergesort in its internal implementation.

# Syntax :: sort(first index,last index);

*/

template <typename T>
void printVector(vector<T> &vec)
{
    cout << "The elements in the vector : ";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

template <typename T>
void printVectorPair(vector<T> &vec)
{
    cout << "The elements in the vector pair : " << endl;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
}

template <typename T>
void printArr(T arr[], int n)
{
    cout << "The elements in the array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool sortBySec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{
    vector<int> v{4, 2, 5, 9, 1, 6};
    printVector(v);

    cout << "After sorting in ascending order." << endl;
    printVector(v);

    int arr[] = {4, 2, 5, 9, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, n);

    sort(arr, arr + n, greater<int>());
    cout << "After sorting in descending order." << endl;
    printArr(arr, n);

    vector<pair<int, int>> vec = {{10, 3}, {20, 1}, {30, 2}};
    printVectorPair(vec);
    cout << "After sorting according to second." << endl;
    sort(vec.begin(), vec.end(), sortBySec);
    printVectorPair(vec);

    return 0;
}