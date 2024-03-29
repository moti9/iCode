#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int getMaxToys(vector<int> &prices, int money)
{
    int sum = 0;
    int count = 0;
    int maxCount = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        sum = count = 0;
        for (int j = i; j < prices.size(); j++)
        {
            if ((sum + prices[j]) <= money)
            {
                sum += prices[j];
                count++;
                maxCount = max(count, maxCount);
            }
            else
            {
                count = 0;
                sum = 0;
                break;
            }
        }
    }
    return maxCount;
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        prices[i] = t;
    }
    int money;
    cin >> money;
    cout << getMaxToys(prices, money) << endl;
    return 0;
}


/*
Question 1: Maximum Toys

prices=[1,4,5,3,2,1,6]

money=6

All sub arrays that sum to less than or equal to 6 .

length 1:  [1] [4] [5] [3] [2] [1] [6]

length 2:  [1,4] [3,2] [2,1] 

length 3: [3,2,1]

The longest of these or the maximum number of toys that can be purchased is 3.
*/
