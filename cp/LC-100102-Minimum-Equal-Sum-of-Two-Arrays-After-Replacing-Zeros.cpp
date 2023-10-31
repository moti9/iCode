#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long minSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;

        for (int i = 0; i < max(n, m); i++)
        {
            if (i < n)
            {
                sum1 += (long long)nums1[i];
                if (nums1[i] == 0)
                {
                    sum1++;
                    z1++;
                }
            }
            if (i < m)
            {
                sum2 += (long long)nums2[i];
                if (nums2[i] == 0)
                {
                    sum2++;
                    z2++;
                }
            }
        }

        if (sum1 == sum2)
        {
            return sum1;
        }
        else
        {
            if (sum1 < sum2)
            {
                if (z1 > 0)
                {
                    return sum2;
                }
                else
                {
                    return -1;
                }
            }
            else
            {
                if (z2 > 0)
                {
                    return sum1;
                }
                else
                {
                    return -1;
                }
            }
        }
    }
};

int main()
{

    return 0;
}