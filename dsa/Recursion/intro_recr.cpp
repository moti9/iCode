#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int ct = 1;

void func()
{
    cout << ct << endl;
    ct += 1;
    if (ct == 3)
    {
        return;
    }

    func();
}
int main()
{
    func();

    return 0;
}


/*
Recursion- A function calling itself 
            Until a specified condition.

            Specified condition is called as Base Condition.

*/