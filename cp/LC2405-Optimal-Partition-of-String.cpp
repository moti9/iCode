#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<char> st;
        int ct = 0;
        for (auto c : s)
        {
            int sz = st.size();
            st.insert(c);
            if (st.size() == sz)
            {
                ct++;
                st.clear();
                st.insert(c);
            }
        }
        return ct;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.partitionString(s) << endl;

    return 0;
}