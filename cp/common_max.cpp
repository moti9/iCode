#include <bits/stdc++.h>

using namespace std;

bool shareDigits(int num1, int num2)
{
    string n1 = to_string(num1);
    string n2 = to_string(num2);

    for (char na : n1)
    {
        for (char nb : n2)
        {
            if (na == nb)
                return true;
        }
    }
    return false;
}

int solution(vector<int> &A)
{

    int maxSum = -1;

    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = i + 1; j < A.size(); ++j)
        {
            if (!shareDigits(A[i], A[j]))
            {
                int currentSum = A[i] + A[j];
                maxSum = max(maxSum, currentSum);
            }
        }
    }

    return maxSum;
}

int main()
{
    // Example usage
    vector<int> A1 = {53, 1, 36, 103, 53, 5};
    cout << "Example 1: " << solution(A1) << endl; // Output: 108

    vector<int> A2 = {9, 19, 99, 29};
    cout << "Example 2: " << solution(A2) << endl; // Output: -1

    vector<int> A3 = {6, 17, 71, 66, 17, 6};
    cout << "Example 3: " << solution(A3) << endl; // Output: 137

    vector<int> A4 = {15, 0, 105};
    cout << "Example 4: " << solution(A4) << endl; // Output: 15

    return 0;
}
