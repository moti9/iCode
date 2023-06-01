#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class UndergroundSystem
{
    unordered_map<int, pair<string, int>> start_travel;
    unordered_map<string, unordered_map<string, pair<int, int>>> station_pair;

public:
    UndergroundSystem()
    {
        start_travel.clear();
        station_pair.clear();
    }

    void checkIn(int id, string stationName, int t)
    {
        start_travel[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        string start = start_travel[id].first;
        int start_time = start_travel[id].second;
        int time = t - start_time;
        station_pair[start][stationName].first += time;
        station_pair[start][stationName].second += 1;
    }

    double getAverageTime(string startStation, string endStation)
    {
        double time = (double)station_pair[startStation][endStation].first;
        double travelars = (double)station_pair[startStation][endStation].second;
        return time / travelars;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main()
{

    return 0;
}