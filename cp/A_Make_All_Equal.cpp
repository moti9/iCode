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
        vector<int> arr(n);
        int max_fr = 0;
        int mf_num = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            umap[arr[i]]++;
            if (umap[arr[i]] > max_fr)
            {
                max_fr = umap[arr[i]];
                mf_num = arr[i];
            }
        }

        // bool do_ops = true;
        int cnt_ops = n - max_fr;
        // while (do_ops && umap.size() > 1)
        // {
        //     for (int prev = 0; prev < arr.size(); prev++)
        //     {
        //         int m = arr.size();
        //         int next = (prev + 1) % m;
        //         if (arr[prev] <= arr[next])
        //         {
        //             if (arr[prev] != mf_num)
        //             {
        //                 do_ops = true;
        //                 umap[arr[prev]]--;
        //                 if (umap[arr[prev]] == 0)
        //                     umap.erase(arr[prev]);
        //                 arr.erase(arr.begin() + prev);
        //                 cnt_ops++;
        //             }
        //             else if (arr[next] != mf_num)
        //             {
        //                 do_ops = true;
        //                 umap[arr[next]]--;
        //                 if (umap[arr[next]] == 0)
        //                     umap.erase(arr[next]);
        //                 arr.erase(arr.begin() + next);
        //                 cnt_ops++;
        //             }
        //         }
        //     }
        // }
        cout << cnt_ops << "\n";
    }
    return 0;
}