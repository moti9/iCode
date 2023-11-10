#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SeatManager
{
    set<int> seats;
    int marker;

public:
    SeatManager(int n)
    {
        marker = 1;
    }

    int reserve()
    {
        if (!seats.empty())
        {
            int seatNumber = *seats.begin();
            seats.erase(seats.begin());
            return seatNumber;
        }
        return marker++;
    }

    void unreserve(int seatNumber)
    {
        seats.insert(seatNumber);
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