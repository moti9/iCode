#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MOD 1000000007

class Solution
{
    int countSetBit(int n)
    {
        int cnt = 0;
        while (n)
        {
            cnt += (n & 1);
            n >>= 1;
        }
        return cnt;
    }

public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> answer;
        for (int hour = 0; hour < 12; hour++)
        {
            for (int minute = 0; minute < 60; minute++)
            {
                if (countSetBit(hour) + countSetBit(minute) == turnedOn)
                {
                    answer.push_back(to_string(hour) + ":" + ((minute < 10) ? "0" : "") + to_string(minute));
                }
            }
        }

        return answer;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int turnedOn;
    cin >> turnedOn;
    Solution sol;
    vector<string> times = sol.readBinaryWatch(turnedOn);

    for (auto time : times)
    {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}