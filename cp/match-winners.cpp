#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> countTeamAWinnerLessThanTeamB(vector<int> &teama, vector<int> &teamb)
{
    sort(teama.begin(), teama.end());
    vector<int> result;
    for (int &tb : teamb)
    {
        int ind = upper_bound(teama.begin(), teama.end(), tb) - teama.begin();
        result.push_back(ind);
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> teamA(n);
    for (int i = 0; i < n; i++)
    {
        cin >> teamA[i];
    }
    vector<int> teamB(n);
    for (int i = 0; i < n; i++)
    {
        cin >> teamB[i];
    }
    vector<int> result = countTeamAWinnerLessThanTeamB(teamA, teamB);
    for (auto &rs : result)
        cout << rs << " ";
    cout << endl;

    return 0;
}