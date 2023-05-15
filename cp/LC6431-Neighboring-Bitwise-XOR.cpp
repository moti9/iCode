#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
public:
    bool doesValidArrayExist(vector<int> &derived)
    {
        int n = derived.size();
        vector<int> original(n);
        vector<int> memo(n, -1); 
        
        original[0] = derived[0] ^ derived[n - 1];
        if (original[0] != 0 && original[0] != 1)
        {
            return false;
        }
        memo[0] = original[0]; 

       
        for (int i = 1; i < n; i++)
        {
            // Check if we have already computed the value for this index
            if (memo[i] == -1)
            {
                original[i] = derived[i] ^ original[i - 1];
                memo[i] = original[i]; // store the value in the memo table
            }
            else
            {
                original[i] = memo[i]; // use the value from the memo table
            }
            if (original[i] != 0 && original[i] != 1)
            {
                return false;
            }
        }

        // All elements of the original array are binary, so a valid array exists
        return true;
    }
};

int main()
{

    return 0;
}