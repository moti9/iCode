#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else if (c == ')' && st.top() == '(' || c == '}' && st.top() == '{' || c == ']' && st.top() == '[')
            {
                st.pop();
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string s;
    cin >> s;
    Solution sol;
    cout << sol.isValid(s) << endl;

    return 0;
}