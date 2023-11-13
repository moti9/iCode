#include <bits/stdc++.h>
using namespace std;

int n, m, q;
unordered_map<string, int> indof;
vector<string> nodes;
unordered_map<string, int> islocked;
unordered_map<string, set<string>> lockedchildren;

int parent(int i)
{
    if (i == 0 || i >= nodes.size())
    {
        return -1;
    }
    return (i - 1) / m;
}

bool Lock(string s, int uid)
{
    if (islocked.find(s) != islocked.end())
    {
        return false;
    }
    if (lockedchildren[s].size() > 0)
        return false;
    int i = indof[s];
    while (i != -1)
    {
        if (islocked.find(nodes[i]) != islocked.end())
            return false;
        i = parent(i);
    }
    i = parent(indof[s]);
    while (i != -1)
    {
        lockedchildren[nodes[i]].insert(s);
        i = parent(i);
    }
    islocked[s] = uid;
    return true;
}

bool unlock(string s, int uid)
{
    if (islocked.find(s) == islocked.end())
        return false;
    int lockedwithid = islocked[s];
    if (lockedwithid != uid)
        return false;
    islocked.erase(s);
    int i = parent(indof[s]);
    while (i != -1)
    {
        lockedchildren[nodes[i]].erase(s);
        i = parent(i);
    }
    return true;
}

bool upgrade(string s, int uid)
{
    int i = indof[s];
    if (islocked.find(s) != islocked.end())
        return false;
    unordered_set<int> ids;
    for (auto it = lockedchildren[s].begin(); it != lockedchildren[s].end(); it++)
    {
        ids.insert(islocked[(*it)]);
    }
    if (ids.size() > 1)
        return false;
    if (ids.size() == 0)
    {
        return false;
    }
    int tid = *(ids.begin());
    set<string> temp(lockedchildren[s]);
    for (auto it = temp.begin(); it != temp.end(); it++)
    {
        unlock((*it), uid);
    }
    unlock(s, uid);
    return Lock(s, uid);
}

int main()
{
    cin >> n >> m >> q;
    nodes.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i];
        indof[nodes[i]] = i;
    }

    while (q--)
    {
        int op, usid;
        string nodename;
        cin >> op >> nodename >> usid;

        if (op < 1 || op > 3 || indof.find(nodename) == indof.end())
        {
            cout << "false" << endl;
            continue;
        }

        if (op == 1)
        {
            if (Lock(nodename, usid))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (op == 2)
        {
            if (unlock(nodename, usid))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else
        {
            if (upgrade(nodename, usid))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
    }
    return 0;
}
