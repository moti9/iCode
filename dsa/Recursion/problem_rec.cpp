/*
P1- Print name 5 times
*/

/*

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void func(int i, int n)
{
    cout << "Moti" << endl;
    if (i == n)
    {
        return;
    }
    func(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int i = 1;
    func(i, n);

    return 0;
}
*/

/*
    P2-Print linearly from 1 to n
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void print1ton(int i, int n)
{
    cout << i << " ";
    if (i == n)
    {
        return;
    }
    print1ton(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    int i = 1;
    print1ton(i, n);

    return 0;
}
*/

/*
    P3-Print linearly from N to 1
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printNto1(int n)
{
    cout << n << " ";
    if (n == 1)
    {
        return;
    }
    printNto1(n - 1);
}

int main()
{
    int n;
    cin >> n;
    printNto1(n);

    return 0;
}
*/

/*
    P4-Print linearly from 1 to N(Using backtracking)
*/

// /*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void print1toN(int n)
{
    if (n == 0)
    {
        return;
    }
    print1toN(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cin >> n;
    int i = 1;
    print1toN(n);

    return 0;
}
// */

/*
    P5-Print linearly from N to 1(Using backtracking)
*/

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printNto1(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printNto1(i + 1, n);
    cout << i << " ";
}

int main()
{
    int n;
    cin >> n;
    int i = 1;
    printNto1(i, n);

    return 0;
}
*/