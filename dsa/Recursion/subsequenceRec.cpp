#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printAllSubSeq(int index, int n, vector<int> nums, vector<vector<int>> &allseq, vector<int> ds)
{
    if (index >= n)
    {
        allseq.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    printAllSubSeq(index+1, n, nums, allseq, ds);
    ds.pop_back();
    printAllSubSeq(index + 1, n, nums, allseq, ds);
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
    vector<vector<int>> allseq;
    vector<int> ds;
    printAllSubSeq(0, n, nums, allseq, ds);

    for (auto x : allseq)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}