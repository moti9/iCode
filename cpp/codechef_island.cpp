#include <iostream>

using namespace std;
int main()
{
    int T, x, xr, y, yr, D;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> x >> y >> xr >> yr >> D;
    }
    float a = 0.0, b = 0.0, min = 0.0;
    for (int i = 0; i < T; i++, a = 0.0, b = 0.0)
    {
        a = (x / xr) * 1.0;
        b = (y / yr) * 1.0;

        if (a < b)
            min = b;
        else if (a > b)
            min = b;
        else
            min = a;

        if (min >= D)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
