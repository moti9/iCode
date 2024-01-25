#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int deliveryTime(int speed, int x)
{
    return speed * (x * x - x + 1);
}

int totalDeliveryTime(int boxes, vector<int> &speeds)
{
    int maxTime = 0;
    for (int speed : speeds)
    {
        maxTime = max(maxTime, deliveryTime(speed, boxes));
    }
    return maxTime;
}

int minTimeToCompleteOrders(int boxes, int numTrucks, vector<int> &truckSpeeds)
{
    return totalDeliveryTime(boxes, truckSpeeds);
}

int main()
{
    int inputBoxes, inputTrucks;
    cin >> inputBoxes;
    cin >> inputTrucks;

    vector<int> inputSpeeds(inputTrucks);
    for (int i = 0; i < inputTrucks; ++i)
    {
        cin >> inputSpeeds[i];
    }

    int result = minTimeToCompleteOrders(inputBoxes, inputTrucks, inputSpeeds);
    cout << result;

    return 0;
}
