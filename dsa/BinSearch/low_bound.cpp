#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    int a[] = {1, 4, 5, 6, 9, 9};
    int m = sizeof(a) / sizeof(a[0]);
    cout << lower_bound(a, a + m, 4) - a << endl;
    cout << lower_bound(a, a + m, 7) - a << endl;
    cout << lower_bound(a, a + m, 10) - a << endl;
    cout << lower_bound(a, a + m, 9) - a << endl;

    //If present then return index of first occurence
    //Otherwise return the index of next greater element

    return 0;
}