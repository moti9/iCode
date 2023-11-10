#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; ++i)
        {
            pq.push(i);
        }
    }

    int reserve()
    {
        if (pq.empty())
        {
            return -1;
        }

        int seatNumber = pq.top();
        pq.pop();
        return seatNumber;
    }

    void unreserve(int seatNumber)
    {
        pq.push(seatNumber);
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