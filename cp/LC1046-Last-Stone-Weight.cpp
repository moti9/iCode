#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    void operation(vector<int> &stones)
    {
        sort(stones.begin(), stones.end());
        int last = stones.back();
        stones.pop_back();
        int slast = stones.back();
        stones.pop_back();
        if (last != slast)
        {
            stones.push_back(last - slast);
            
        }
    }

public:
    int lastStoneWeight(vector<int> &stones)
    {
        while (stones.size() > 1)
        {
            operation(stones);
        }
        if (stones.size() == 0)
            return 0;
        return stones[0];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> stones(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stones[i];
    }
    Solution sol;
    cout << sol.lastStoneWeight(stones) << endl;

    return 0;
}