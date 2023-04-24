#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printSubSeqOfSumK(int index, int n, int k, int sum, vector<int> nums, vector<vector<int>> &subseq, vector<int> ds)
{
    if (index == n)
    {
        if (sum == k)
        {
            subseq.push_back(ds);
        }
        return;
    }
    ds.push_back(nums[index]);
    sum += nums[index];
    printSubSeqOfSumK(index + 1, n, k, sum, nums, subseq, ds);
    ds.pop_back();
    sum -= nums[index];
    printSubSeqOfSumK(index + 1, n, k, sum, nums, subseq, ds);
}

bool printOneSeqOfSumK(int index, int n, int k, int sum, vector<int> nums, vector<int> &ds)
{
    if (index == n)
    {
        if (sum == k)
        {
            return true;
        }
        return false;
    }
    ds.push_back(nums[index]);
    sum += nums[index];
    if (printOneSeqOfSumK(index + 1, n, k, sum, nums, ds))
    {
        return true;
    }
    ds.pop_back();
    sum -= nums[index];
    if (printOneSeqOfSumK(index + 1, n, k, sum, nums, ds))
    {
        return true;
    }
    return false;
}

int countSubSeqOfSumK(int index, int n, int k, int sum, vector<int> nums)
{
    if (index == n)
    {
        if (sum == k)
        {
            return 1;
        }
        return 0;
    }
    sum += nums[index];
    int left = countSubSeqOfSumK(index + 1, n, k, sum, nums);
    sum -= nums[index];
    int right = countSubSeqOfSumK(index + 1, n, k, sum, nums);

    return left + right;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    vector<vector<int>> subseq;
    vector<int> ds;

    printSubSeqOfSumK(0, n, k, 0, nums, subseq, ds);
    cout << "All sub sequences of sum k" << endl;
    for (auto x : subseq)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << "Number of subsequences : " << subseq.size() << endl;

    cout << "One sub sequences of sum k" << endl;
    printOneSeqOfSumK(0, n, k, 0, nums, ds);
    for (auto x : ds)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Number of subsequences : " << countSubSeqOfSumK(0, n, k, 0, nums) << endl;

    return 0;
}