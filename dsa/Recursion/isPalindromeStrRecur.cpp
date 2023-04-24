#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void isPalindrome(string s, int i, int n)
{
    if (i >= n / 2)
    {
        cout << "Palindrome String" << endl;
        return;
    }
    if (s[i] != s[n - i - 1])
    {
        cout << "Not a Palindrome String" << endl;
        return;
    }
    return isPalindrome(s, i + 1, n);
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    isPalindrome(s, 0, n);

    return 0;
}