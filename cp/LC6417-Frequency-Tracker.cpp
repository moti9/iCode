#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class FrequencyTracker
{
private:
    std::unordered_map<int, int> frequencies;
    std::unordered_map<int, int> freqFreq;

public:
    FrequencyTracker() {}

    void add(int number)
    {
        freqFreq[frequencies[number]]--;
        frequencies[number]++;
        freqFreq[frequencies[number]]++;
    }

    void deleteOne(int number)
    {
        if (frequencies.find(number) != frequencies.end())
        {
            freqFreq[frequencies[number]]--;
            frequencies[number]--;
            if (frequencies[number] == 0)
            {
                frequencies.erase(number);
            }
            else
            {
                freqFreq[frequencies[number]]++;
            }
        }
    }

    bool hasFrequency(int frequency)
    {
        return freqFreq.find(frequency) != freqFreq.end() && freqFreq[frequency] > 0;
    }
};

int main()
{
    FrequencyTracker ft;
    int nop;
    cin >> nop;
    for (int i = 0; i < nop; i++)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            ft = FrequencyTracker();
        }
        else if (op == 1)
        {
            int num;
            cin >> num;
            ft.add(num);
            cout << "null"
                 << " ";
        }
        else if (op == 2)
        {
            int num;
            cin >> num;
            ft.deleteOne(num);
            cout << "null"
                 << " ";
        }
        else if (op == 3)
        {
            int freq;
            cin >> freq;
            cout << ft.hasFrequency(freq) << " ";
        }
    }

    return 0;
}