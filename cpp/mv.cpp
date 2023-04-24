#include <iostream>

using namespace std;
int main()
{
    int T, N, M, X, Y, a, b;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        cin >> X >> Y;
        cin >> a >> b;
    }
    for (int i = 0; i < T; i++)
    {
        if (X == a)
        {
            if (Y >= b)
                cout << "YES" << endl;  
//            else
//                cout << "NO" << endl;
        }
        else if (X > a)
        {
            if (Y >= b)
                cout << "YES" << endl;
//            else
//                cout << "NO" << endl;
        }
         

        else if (Y == b)
        {
            if (X >= a)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (Y > b)
        {
            if (X >= a)
                cout << "YES" << endl;
//            else
//                cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
