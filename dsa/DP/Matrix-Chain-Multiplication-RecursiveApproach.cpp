#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    int multMatrix(int i, int j, int arr[])
    {
        if (i == j)
        {
            return 0;
        }
        int minSteps = 1e9;
        for (int k = i; k < j; k++)
        {
            int steps = arr[i - 1] * arr[k] * arr[j] + multMatrix(i, k, arr) + multMatrix(k + 1, j, arr);
            minSteps = min(minSteps, steps);
        }
        return minSteps;
    }

public:
    int matrixMultiplication(int N, int arr[])
    {
        return multMatrix(1, N - 1, arr);
    }
};

int main()
{

    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    cout << ob.matrixMultiplication(N, arr) << endl;

    return 0;
}
