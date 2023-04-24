#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> numbers;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        numbers.push_back(i);
    }
    k -= 1;
    numbers.push_back(n);
    vector<int> ans;
    while (true)
    {
        ans.push_back(numbers[k / fact]);
        numbers.erase(numbers.begin() + k / fact);
        if (numbers.size() == 0)
        {
            break;
        }
        k = k % fact;
        fact /= numbers.size();
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}