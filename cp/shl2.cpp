#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<int, int> getReducedForm(int dy, int dx)
{
    int g = gcd(abs(dy), abs(dx));

    bool sign = (dy < 0) ^ (dx < 0);

    if (sign)
        return make_pair(-abs(dy) / g, abs(dx) / g);
    else
        return make_pair(abs(dy) / g, abs(dx) / g);
}

int minLinesToCoverPoints(vector<vector<int>> &points, int N,int xO, int yO)
{
    set<pair<int, int>> st;
    pair<int, int> temp;
    int minLines = 0;

    for (int i = 0; i < N; i++)
    {
        int curX = points[i][0];
        int curY = points[i][1];

        if (curX != xO || curY != yO)
        {
            temp = getReducedForm(curY - yO, curX - xO);
            if (st.find(temp) == st.end())
            {
                st.insert(temp);
                minLines++;
            }
        }
    }

    return minLines;
}

int minimumStrainghtRoutes(vector<vector<int>> coordinates)
{
    int n = coordinates.size();
    int res = 1e9;
    for (int i = 0; i < n; i++)
    {
        res = min(res, minLinesToCoverPoints(coordinates, n, coordinates[i][0], coordinates[i][1]));
    }
    return res;
}

int main()
{
    int coordinates_row;
    int coordinates_col;
    cin >> coordinates_row;
    cin >> coordinates_col;

    vector<vector<int>> coordinates;

    for (int idx = 0; idx < coordinates_row; idx++)
    {
        vector<int> temp_vector(2);
        for (int jdx = 0; jdx < coordinates_col; jdx++)
        {
            cin >> temp_vector[jdx];
        }
        coordinates.push_back(temp_vector);
    }

    int result = minimumStrainghtRoutes(coordinates);

    // Output the result
    cout << result << endl;

    return 0;
}
