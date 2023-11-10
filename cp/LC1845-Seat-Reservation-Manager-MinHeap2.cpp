#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> seats;
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
            int seatNumber = seats.top();
            seats.pop();
            return seatNumber;
        }
        return marker++;
    }

    void unreserve(int seatNumber)
    {
        seats.push(seatNumber);
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