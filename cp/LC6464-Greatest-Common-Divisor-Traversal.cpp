#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    class UnionFind
    {
    private:
        std::vector<int> parent;
        std::vector<int> rank;

    public:
        UnionFind(int size)
        {
            parent.resize(size);
            rank.resize(size, 1);
            for (int i = 0; i < size; i++)
            {
                parent[i] = i;
            }
        }

        int find(int x)
        {
            if (parent[x] != x)
            {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void unite(int x, int y)
        {
            int rootX = find(x);
            int rootY = find(y);

            if (rootX != rootY)
            {
                if (rank[rootX] < rank[rootY])
                {
                    parent[rootX] = rootY;
                }
                else if (rank[rootX] > rank[rootY])
                {
                    parent[rootY] = rootX;
                }
                else
                {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
            }
        }
    };

    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        UnionFind uf(n);
        unordered_map<int, vector<int>> fact;
        for (int i = 0; i < n; i++)
        {
            for (int j = 2; j * j <= nums[i]; j++)
            {
                if (nums[i] % j == 0)
                {
                    fact[j].push_back(i);
                    while (nums[i] % j == 0)
                    {
                        nums[i] /= j;
                    }
                }
            }
            if (nums[i] > 1)
            {
                fact[nums[i]].push_back(i);
            }
        }
        for (auto &fp : fact)
        {
            vector<int> &ind = fp.second;
            for (int i = 1; i < ind.size(); i++)
            {
                uf.unite(ind[i - 1], ind[i]);
            }
        }
        int root = uf.find(0);
        for (int i = 1; i < n; i++)
        {
            if (uf.find(i) != root)
            {
                return false;
            }
        }

        return true;
    }
};

/*
class Solution
{
public:
    bool canTraverseAllPairs(vector<int> &nums)
    {
        int n = nums.size();
        std::unordered_set<int> indices;

        // Create a helper function to calculate gcd using memoization
        std::unordered_map<int, std::unordered_map<int, int>> gcdMemo;
        std::function<int(int, int)> calculateGCD = [&](int a, int b)
        {
            if (gcdMemo.count(a) && gcdMemo[a].count(b))
            {
                return gcdMemo[a][b];
            }

            int result = b == 0 ? a : calculateGCD(b, a % b);
            gcdMemo[a][b] = result;
            return result;
        };

        // Initialize the set with all indices
        for (int i = 0; i < n; i++)
        {
            indices.insert(i);
        }

        // Check if it is possible to traverse between all pairs of indices
        while (!indices.empty())
        {
            int start = *indices.begin();
            std::unordered_set<int> visited{start};
            std::unordered_set<int> queue{start};
            indices.erase(start);

            // Perform BFS to find all reachable indices from the current start index
            while (!queue.empty())
            {
                int current = *queue.begin();
                queue.erase(current);

                // Traverse all remaining indices and check if they can be reached
                for (auto it = indices.begin(); it != indices.end();)
                {
                    int next = *it;
                    if (calculateGCD(nums[current], nums[next]) > 1)
                    {
                        visited.insert(next);
                        queue.insert(next);
                        it = indices.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
            }

            // Check if all indices have been visited
            if (visited.size() != n)
            {
                return false;
            }
        }

        return true;
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.canTraverseAllPairs(nums) << endl;

    return 0;
}