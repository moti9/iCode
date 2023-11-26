#include <bits/stdc++.h>
using namespace std;

map<char, int> mp;

void load_map()
{
    int q = 0;
    char ch = 'a';

    while (ch != 'z')
    {
        mp[ch] = q;
        q++;
        ch++;
    }

    mp['z'] = 25;
    mp[':'] = 26;
    mp['/'] = 27;
    mp['.'] = 28;
}

int find_hash_value(string x)
{
    int r = 0;

    for (int i = 0; i < x.size(); i++)
    {
        r += mp[x[i]];
    }

    return r;
}

string getHashedURL(string url, string hash_string, int k)
{
    load_map();
    string r = "";

    int m = hash_string.size();

    for (int i = 0; i < url.size(); i += k)
    {
        string x;
        if (i + k - 1 <= url.size())
            x = url.substr(i, k);

        else
            x = url.substr(i, url.size() - i + 1);

        // cout<<"SUBSTR: "<<x<<endl;

        int val = find_hash_value(x);

        // cout<<"VAL: "<<val<<endl;
        val = val % m;

        // cout<<"VAL: "<<val<<endl;

        // cout<<"Hashval: "<<hash_string[val]<<endl;

        r += (hash_string[val]);
    }

    return r;
}

int main()
{
    string x = getHashedURL("https://xyz.com", "pqrst", 4);

    cout << "X: " << x << endl;

    return 0;
}