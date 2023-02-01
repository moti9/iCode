#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

// Greedy Approach
class Solution
{
    bool genStr(int n, string &sub, string &st)
    {
        string s = sub.substr(0, n), temp = "";
        int loop = st.size() / n;
        while (loop--)
        {
            temp += s;
        }
        return temp == st;
    }

    bool check(int n, string &s1, string &s2)
    {
        if (genStr(n, s2, s1) == false || genStr(n, s2, s2) == false)
        {
            return false;
        }
        return true;
    }

public:
    string gcdOfStrings(string str1, string str2)
    {
        string ans = "";
        int n = str1.size();
        int m = str2.size();

        if (m > n)
        {
            swap(n, m);
            swap(str1, str2);
        }

        if (check(m, str1, str2))
        {
            return str2;
        }
        for (int i = m / 2; i > 0; i--)
        {
            if (n % i == 0 && m % i == 0)
            {
                if (check(i, str1, str2))
                {
                    return str2.substr(0, i);
                }
            }
        }

        return ans;
    }
};

// Optimal solution
string findGCP(string &str1, string &str2)
{
    return str1 + str2 == str2 + str1 ? str1.substr(0, __gcd(str1.size(), str2.size())) : "";
}

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    Solution sol;
    cout << sol.gcdOfStrings(s1, s2) << endl;
    cout << findGCP(s1, s2) << endl;

    return 0;
}