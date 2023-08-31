#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool checkArmstrong(int n)
{
    int originalNum = n;
    int numDigits = 0;
    int sum = 0;

    while (n > 0)
    {
        n /= 10;
        numDigits++;
    }

    n = originalNum;

    while (n > 0)
    {
        int digit = n % 10;
        sum += pow(digit, numDigits);
        n /= 10;
    }
    return sum == originalNum;
}

int main()
{
    int n;
    cin >> n;

    cout << checkArmstrong(n) << endl;

    return 0;
}