#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll ttt = 1;
    cin >> ttt;
    while (ttt--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool used_arr[n + 2] = {false};
        used_arr[arr[0]] = true;
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            int nb_l = arr[i] - 1, nb_r = arr[i] + 1;
            if (used_arr[nb_l])
            {
                int nb_l_nb_l = nb_l - 1, nb_l_nb_r = nb_l + 1;
                if (!used_arr[nb_l_nb_l] || !used_arr[nb_l_nb_r])
                {
                    used_arr[arr[i]] = true;
                    continue;
                }
            }
            if (used_arr[nb_r])
            {
                int nb_r_nb_l = nb_r - 1, nb_r_nb_r = nb_r + 1;
                if (!used_arr[nb_r_nb_l] || !used_arr[nb_r_nb_r])
                {
                    used_arr[arr[i]] = true;
                    continue;
                }
            }

            cout << "NO\n";
            flag = false;
            break;
        }
        if (flag)
            cout << "YES\n";
    }
    return 0;
}