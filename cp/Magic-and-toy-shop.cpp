#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int minimumToys(vector<int> &price, vector<int> &magicalPrice, int M)
{
    int N = price.size();
    int totalPrice = 0;
    int minMagicCount = 0;

    for (int i = 0; i < N; i++)
    {
        totalPrice += magicalPrice[i];
    }

    if (totalPrice > M)
    {
        return -1;
    }

    sort(price.begin(), price.end());
    sort(magicalPrice.begin(), magicalPrice.end());

    for (int i = 0; i < N; i++)
    {
        if (totalPrice <= M)
        {
            break;
        }
        totalPrice = totalPrice - magicalPrice[i] + price[i];
        minMagicCount++;
    }

    if (totalPrice > M)
    {
        return -1;
    }

    return minMagicCount;
}

int main()
{
    int N, M;
    cout << "Enter the number of toys (N): ";
    cin >> N;
    cout << "Enter the budget (M): ";
    cin >> M;

    vector<int> price(N), magicalPrice(N);
    cout << "Enter the prices of the toys: ";
    for (int i = 0; i < N; i++)
    {
        cin >> price[i];
    }
    cout << "Enter the magical prices of the toys: ";
    for (int i = 0; i < N; i++)
    {
        cin >> magicalPrice[i];
    }

    int minMagicCount = minimumToys(price, magicalPrice, M);
    cout << "Minimum number of toys to apply magic on: " << minMagicCount << endl;

    return 0;
}
