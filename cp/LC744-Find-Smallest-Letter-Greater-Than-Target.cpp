#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Binary Search
// TC- O(logN)
// SC- O(1)

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int n = letters.size();
        int ind = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if (ind < n)
        {
            return letters[ind];
        }
        return letters[0];
    }
};

// Brute Force
// TC- O(N)
// SC- O(1)
/*
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        for (auto letter : letters)
        {
            if (letter > target)
                return letter;
        }
        return letters[0];
    }
};
*/

int main()
{
    int n;
    cin >> n;
    vector<char> letters(n);
    for (int i = 0; i < n; i++)
    {
        cin >> letters[i];
    }

    char target;
    cin >> target;

    Solution sol;

    cout << sol.nextGreatestLetter(letters, target) << endl;

    return 0;
}