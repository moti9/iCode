#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int num_boats = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
            }
            j--;
            num_boats++;
        }
        return num_boats;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> people(n);
    for (int i = 0; i < n; i++)
    {
        cin >> people[i];
    }
    int limit;
    cin >> limit;
    Solution sol;
    cout << sol.numRescueBoats(people, limit) << endl;

    return 0;
}