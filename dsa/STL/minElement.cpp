#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/*

# Syntax :: *min_element(first index,last index);

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
    vector<int> v{4, 2, 5, 9, 1, 6};
    printVector(v);

    cout << "The maximum element is: " << *min_element(v.begin(), v.end()) << endl;

    return 0;
}