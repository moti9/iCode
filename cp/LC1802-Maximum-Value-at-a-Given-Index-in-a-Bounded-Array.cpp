#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    long getSum(long val, long index, long n)
    {
        long sum = 0;
        // left sequence
        if (val > index)
        {
            // complete sequence{ val-index,val-index+1,...val-1,val} of size {index+1}
            // Sn=(A0+An)*(N/2)
            sum += (val + val - index) * (index + 1) / 2;
        }
        else
        {
            // partial sequence {1,2,3,...,val} of size val
            // Sn=N*(N+1)/2
            sum += val * (val + 1) / 2;
            // remaining 1's {index -{val - 1}}
            sum += (index - val + 1);
        }
        // right sequence
        if (val >= n - index)
        {
            // complete sequence {val,val-1,val-2,...,val-n+index+1} of size {n-index}
            // Sn=(A0+An)*(N/2)
            sum += (val + val - n + index + 1) * (n - index) / 2;
        }
        else
        {
            // partial sequence {val,val-1,...,3,2,1} of size val
            // Sn=N*(N+1)/2
            sum += val * (val + 1) / 2;
            // remaining 1's {n -index - val}
            sum += (n - index - val);
        }
        return sum - val;
    }

public:
    int maxValue(int n, int index, int maxSum)
    {
        int minVal = 1, maxVal = maxSum;
        while (minVal < maxVal)
        {
            int midVal = (minVal + maxVal + 1) / 2;
            if (getSum(midVal, index, n) <= maxSum)
            {
                minVal = midVal;
            }
            else
            {
                maxVal = midVal - 1;
            }
        }
        return minVal;
    }
};

int main()
{
    int n, index, maxSum;
    cin >> n >> index >> maxSum;

    Solution sol;
    cout << sol.maxValue(n, index, maxSum) << endl;

    return 0;
}