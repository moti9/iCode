#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void findLongestCommonPrefixAfterRotation(int m, int n, string &str1, string &str2)
{
    int position = 0, length = 0;
    int prefixArr[n + 1];
    int k = 0;
    prefixArr[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        while (k > 0 && str2[k] != str2[i - 1])
            k = prefixArr[k];
        if (str2[k] == str2[i - 1])
            ++k;
        prefixArr[i] = k;
    }

    for (int j = 0, i = 0; i < m; i++)
    {
        while (j > 0 && str2[j] != str1[i])
        {
            j = prefixArr[j];
        }
        if (str2[j] == str1[i])
        {
            j++;
        }

        if (j > length)
        {
            length = j;
            position = i - j + 1;
        }
    }

    cout << "Shift = " << position << "\n";
    cout << "Prefix = " << str2.substr(0, length) << "\n";
}

int main()
{
    string str2, str1;
    cin >> str2;
    cin >> str1;
    int n = str2.size();
    str1 = str1 + str1;
    findLongestCommonPrefixAfterRotation(2 * n, n, str1, str2);
    return 0;
}
