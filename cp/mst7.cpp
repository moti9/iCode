/*
Question 3: Amusement park

Constraints:

1 <= number of tickets <= 10^5
1 <= K < Number of digits in Price of ticket
Input Format for Custom Testing:

The first line contains a string,Tickets, denoting the given cost of each ticket.
The next line contains an integer, K, denoting the number of tickets that is to be removed.
Sample Cases:

Sample Input 1
203
2
Sample Output 1
0

*/

#include <bits/stdc++.h>
using namespace std;
int smallestNumber(string num, int k)
{
    if (num.length() <= k)
    {
        return 0;
    }

    unordered_map<char, int> pos;
    for (int i = 0; i < num.length(); i++)
    {
        pos[num[i]] = i;
    }

    string temp = num;

    // Sort the characters in ascending order
    sort(num.begin(), num.end());

    // Get the required substring
    string ans = num.substr(0, num.length() - k);

    vector v;
    for (int i = 0; i < ans.length(); i++)
    {
        v.push_back(pos[ans[i]]);
    }

    // Sort the positions
    sort(v.begin(), v.end());

    string ret;
    for (int i = 0; i < v.size(); i++)
    {
        ret += temp[v[i]];
    }
    int final = stoi(ret);
    return final;
}
int main()
{
    string s;
    cin >> s;

    int k;
    cin >> k;

    int ans = smallestNumber(s, k) % static_cast(pow(10, 9) + 7);
    cout << ans;

    return 0;
}