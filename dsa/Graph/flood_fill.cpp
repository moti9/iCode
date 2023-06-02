#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void dfs(int sr, int sc, vector<vector<int>> img, vector<vector<int>> &ans, int inColor, int nColor, int drow[], int dcol[])
{
    ans[sr][sc] = nColor;
    int n = img.size();
    int m = img[0].size();

    for (int i = 0; i < 4; i++)
    {
        int nrow = sr + drow[i];
        int ncol = sc + dcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && img[nrow][ncol] == inColor && ans[nrow][ncol] != nColor)
        {
            dfs(nrow, ncol, img, ans, inColor, nColor, drow, dcol);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> img(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            cin >> img[i][j];
        }
    }
    int sr, sc;
    cin >> sr >> sc;
    int nColor;
    cin >> nColor;
    int inColor = img[sr][sc];

    vector<vector<int>> ans = img;
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};
    dfs(sr, sc, img, ans, inColor, nColor, drow, dcol);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}