#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solvehere()
{
    int n;
    cin >> n;
    vector<vector<int>> sets;
    unordered_map<int, int> mp;
    unordered_set<int> ans_set;
    for (int ni = 0; ni < n; ni++)
    {
        int k;
        cin >> k;
        vector<int> num_set;
        for (int i = 0; i < k; i++)
        {
            cin >> num_set[i];
            mp[num_set[i]]++;
            ans_set.insert(num_set[i]);
        }
        sets.push_back(num_set);
    }
    if (n == 1)
    {
        cout << 0 << "\n";
        return;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int set_size = ans_set.size();
        for (int j = 0; j < sets[i].size(); j++)
        {
            if(mp[sets[i][j]] == 1)
            {
                set_size -= 1;
            }
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        solvehere();
    }
    return 0;
}
