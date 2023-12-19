#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canBakeCookies(int mid, const vector<int> &ingredients, const vector<int> &available, int k)
{
    long long neededMagicPowder = 0;

    for (int i = 0; i < ingredients.size(); ++i)
    {
        long long needed = 1LL * mid * ingredients[i] - available[i];
        if (needed > 0)
        {
            neededMagicPowder += needed;
        }
    }

    return neededMagicPowder <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> ingredients(n);
    vector<int> available(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ingredients[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> available[i];
    }

    int low = 0, high = 2e9;

    while (low < high)
    {
        int mid = (low + high + 1) / 2;

        if (canBakeCookies(mid, ingredients, available, k))
        {
            low = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << low << endl;

    return 0;
}
