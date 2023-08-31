#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int uniquePositions(string moves, long long k)
    {
        unordered_set<long long> st;
        st.insert(0);
        long long pos = 0;
        int n = moves.length();
        for (int i = 0; i < n; i++)
        {
            if (moves[i] == 'F')
            {
                pos += k;
                st.insert(pos);
            }
            else
            {
                pos -= k;
                st.insert(pos);
            }
        }
        return (int)st.size();
    }
};

int main()
{
    string moves;
    cin >> moves;
    long long k;
    cin >> k;
    Solution sol;
    cout << sol.uniquePositions(moves, k) << endl;
    return 0;
}