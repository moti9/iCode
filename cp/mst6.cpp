/*
Question 2: Stepping Numbers
Problem Description :

Stepping Numbers are numbers in which the adjacent digits differ by 1. For example, 123, 545, and 98 are stepping numbers, while 321, 444, and 75 are not. The task is to find all stepping numbers in a given range [n, m].

For example
Range: [100, 500]
Stepping Numbers: 101, 121, 123, 210, 212, 232, 234, 321, 323, 343, 345
Explanation: The stepping numbers between 100 and 500 are 101, 121, 123, 210, 212, 232, 234, 321, 323, 343, and 345. These numbers have adjacent digits that differ by 1.
Write code to find out all the stepping numbers in the given range.

Input Format: First line contains two numbers N,M

Output Format: Print all the stepping numbers present in the range.

Constraints: 0 <= N < M <= 1,000,000,000

*/

#include <bits/stdc++.h>
using namespace std;

void displaySteppingNumbers(int n, int m)
{
    queue<int> q;
    for (int i = 1; i <= 9; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int stepNum = q.front();
        q.pop();
        if (stepNum >= n && stepNum <= m)
        {
            cout << stepNum << " ";
        }
        if (stepNum == 0 || stepNum > m)
        {
            continue;
        }
        int lastDigit = stepNum % 10;
        int stepNumA = stepNum * 10 + (lastDigit - 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);
        if (lastDigit == 0)
        {
            q.push(stepNumB);
        }
        else if (lastDigit == 9)
        {
            q.push(stepNumA);
        }
        else
        {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}

int main()
{
    int n, m;
    cout << "Enter the range [n, m]: ";
    cin >> n >> m;
    cout << "Stepping Numbers between " << n << " and " << m << ": ";
    displaySteppingNumbers(n, m);
    return 0;
}