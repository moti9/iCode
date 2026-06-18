#include <vector>
using namespace std;

class NumArray
{
    std::vector<int> pre_sum;

public:
    NumArray(std::vector<int> &nums)
    {
        int n = nums.size();
        pre_sum.resize(n);
        pre_sum[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre_sum[i] = pre_sum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return pre_sum[right];
        }
        return pre_sum[right] - pre_sum[left - 1];
    }
};