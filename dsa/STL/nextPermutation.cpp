#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*
# Syntax :: next_permutation(begin, end);
=>  where, begin is a iterator pointing to 1st element of the container.and, end is an iterator pointing to just after the last element of the container.

=> It returns true if a next lexicographically greater permutation is possible, otherwise, it returns false.
*/

template <typename T>
void printVector(vector<T> &vec)
{
    cout << "The elements in the vector: ";
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec;
    for (int i = 10; i > 0; i--)
    {
        vec.push_back(i);
    }
    printVector(vec);

    cout << "Next permutation ot the vector." << endl;
    next_permutation(vec.begin(), vec.end());
    printVector(vec);

    return 0;
}