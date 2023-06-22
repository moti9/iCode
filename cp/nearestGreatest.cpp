#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v = {10, 5, 11, 6, 20, 12};
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < v.size(); i++)
    {
        /* code */
        if (st.size() == 0)
        {
            ans.push_back(-1);
        }
        else if (!st.empty() && st.top() > v[i])
        {
            ans.push_back(st.top());
        }
        else if (st.top() <= v[i])
        {
            while (!st.empty() && st.top() <= v[i])
            {
                st.pop();
            }
            if (!st.empty() && st.top() > v[i])
            {
                ans.push_back(st.top());
            }
            else
            {
                ans.push_back(-1);
            }
        }
        st.push(v[i]);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}