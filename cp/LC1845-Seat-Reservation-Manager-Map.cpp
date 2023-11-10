#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SeatManager
{
    map<int, int> mp;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            mp[i] = 0;
        }
    }

    int reserve()
    {
        if (mp.empty())
        {
            return -1;
        }

        auto it = mp.begin();
        int seatNumber = it->first;
        mp.erase(it);
        return seatNumber;
    }

    void unreserve(int seatNumber)
    {
        mp[seatNumber] = 0;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main()
{
    SeatManager seatManager = SeatManager(5);
    cout << seatManager.reserve() << endl;
    cout << seatManager.reserve() << endl;
    seatManager.unreserve(2);
    cout << seatManager.reserve() << endl;
    cout << seatManager.reserve() << endl;
    cout << seatManager.reserve() << endl;
    cout << seatManager.reserve() << endl;
    seatManager.unreserve(5);

    return 0;
}