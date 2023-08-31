#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p;
    cin >> n >> p;

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int> weights(st.begin(), st.end());

    for (int i = 0; i < p; i++)
    {
        int nw;
        cin >> nw;

        int insertionPoint = lower_bound(weights.begin(), weights.end(), nw) - weights.begin();
        int currSize = weights.size();

        if (insertionPoint < weights.size() && weights[insertionPoint] == nw)
        {
            cout << currSize - insertionPoint << "\n";
        }
        else
        {
            cout << currSize - insertionPoint + 1 << "\n";
            weights.insert(weights.begin() + insertionPoint, nw);
        }
    }

    return 0;
}
