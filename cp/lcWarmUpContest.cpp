// 3
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int lengthLongestPath(string input)
{
    if (input.empty())
        return 0;

    vector<int> depLen;
    int result = 0, count = 0, depth = 0, isDir = 1;

    for (int i = 0; i < input.length() + 1; ++i)
    {
        switch (input[i])
        {
        case '\0':
        case '\n':
            count = !depth ? count + isDir : depLen[depth - 1] + count + isDir;
            if (depLen.size() > depth)
                depLen[depth] = count;
            else
                depLen.push_back(count);

            if (!isDir)
                result = count > result ? count : result;

            depth = count = 0;
            isDir = 1;
            break;
        case '\t':
            ++depth;
            break;
        case '.':
            isDir = 0;
        default:
            ++count;
        }
    }
    return result;
}

int main()
{
    string path;
    cin >> path;
    // cout << path << endl;
    cout << lengthLongestPath(path) << endl;

    return 0;
}

/*
//2

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int firstUniqChar(string s)
{
    vector<int> fr(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        fr[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (fr[s[i] - 'a'] == 1)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string s;
    cin >> s;
    cout << firstUniqChar(s) << endl;

    return 0;
}
*/

/*
//1

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printLexico(int n)
{
    vector<string> str;
    int i = 1;
    while (i <= n)
    {
        str.push_back(to_string(i));
        i++;
    }
    sort(str.begin(), str.end());

    for (auto x : str)
    {
        cout << x << endl;
    }
}

vector<int> lexicalOrder(int n)
{
    vector<int> ans;
    vector<string> str;
    int i = 1;
    while (i <= n)
    {
        str.push_back(to_string(i));
        i++;
    }
    sort(str.begin(), str.end());

    for (auto x : str)
    {
        ans.push_back(stoi(x));
    }
    return ans;
}

vector<int> lexicalOrder(int n)
{
    vector<int> ans(n);
    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = curr;
        if (curr * 10 <= n)
        {
            curr = curr * 10;
        }
        else
        {
            if (curr >= n)
            {
                curr /= 10;
            }
            curr += 1;
            while (curr % 10 == 0)
            {
                curr /= 10;
            }
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    // printLexico(n);
    vector<int> ans = lexicalOrder(n);
    for (auto x : ans)
    {
        cout << x << " ";
    }

    return 0;
}
*/
