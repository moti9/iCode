#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<double> streamMedian(vector<int> &arr, int n)
{
    vector<double> stream;
    priority_queue<int> medianpq, secondpq;

    for (int i = 0; i < n; i++)
    {
        secondpq.push(arr[i]);
        int temp = secondpq.top();
        secondpq.pop();

        medianpq.push(-1 * temp);
        if (medianpq.size() > secondpq.size())
        {
            temp = medianpq.top();
            medianpq.pop();
            secondpq.push(-1 * temp);
        }
        if (medianpq.size() != secondpq.size())
            stream.push_back(secondpq.top());
        else
            stream.push_back((double)((secondpq.top() * 1.0 - medianpq.top() * 1.0) / 2));
    }
    return stream;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<double> stream = streamMedian(arr, n);
    for (auto &st : stream)
    {
        cout << st << "\n";
    }
    return 0;
}
