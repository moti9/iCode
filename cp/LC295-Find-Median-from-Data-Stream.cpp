#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            return ((double)minHeap.top() + (double)maxHeap.top()) / 2.0;
        }

        if (minHeap.size() > maxHeap.size())
        {
            return (double)minHeap.top();
        }
        return (double)maxHeap.top();
    }
};

int main()
{
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "Median: " << mf.findMedian() << endl;
    mf.addNum(3);
    cout << "Median: " << mf.findMedian() << endl;

    return 0;
}