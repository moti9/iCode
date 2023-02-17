#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    long long distinctNames(vector<string> &ideas)
    {
        long long ct = 0;
        vector<unordered_set<string>> name(26);
        for (auto st : ideas)
            name[st[0] - 'a'].insert(st.substr(1));

        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                unordered_set<string> temp;
                temp.insert(name[i].begin(), name[i].end());
                temp.insert(name[j].begin(), name[j].end());

                ct += (temp.size() - name[i].size()) * (temp.size() - name[j].size());
            }
        }
        ct = ct * 2;
        return ct;
    }
};

long long distinctNames(vector<string> &ideas)
{
    long long ct = 0;
    unordered_map<string, int> mp;
    int n = ideas.size();
    for (int i = 0; i < n; i++)
    {
        mp[ideas[i]]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            string st1 = ideas[i];
            string st2 = ideas[j];
            swap(st1[0], st2[0]);

            if (mp[st1] == 0 && mp[st2] == 0)
            {
                ct++;
            }
        }
    }
    ct = ct * 2;
    return ct;
}

int main()
{
    int n;
    cin >> n;
    vector<string> ideas(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ideas[i];
    }
    Solution sol;
    cout << sol.distinctNames(ideas) << endl;

    return 0;
}