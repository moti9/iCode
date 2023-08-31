#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

class Solution
{
    bool isValid(string &answerKey, int winSize, int k)
    {
        int n = answerKey.length();
        unordered_map<char, int> counter;
        for (int i = 0; i < winSize; i++)
        {
            counter[answerKey[i]]++;
        }
        if (min(counter['T'], counter['F']) <= k)
        {
            return true;
        }
        for (int i = winSize; i < n; i++)
        {
            counter[answerKey[i]]++;
            counter[answerKey[i - winSize]]--;
            if (min(counter['T'], counter['F']) <= k)
            {
                return true;
            }
        }

        return false;
    }

public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int n = answerKey.length();
        int left = 1, right = n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (isValid(answerKey, mid, k))
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main()
{
    string ansKey;
    cin >> ansKey;
    int k;
    cin >> k;

    Solution sol;
    cout << sol.maxConsecutiveAnswers(ansKey, k) << endl;

    return 0;
}