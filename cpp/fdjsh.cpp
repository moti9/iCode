#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define mod 1000000007

void solve()
{
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	// (m * a <= b) ? cout << n * a : cout << (n / m) * b + min((n % m) * a, b);
	if (m * x <= y)
		cout << n * x;
	else
		{
			int temp1 = (n / m) * y;
			int temp2 = n % m;
			if (temp2 * x > y)
				temp2 = y;
			else
				temp2 *= x;
			cout << temp1 + temp2;
		}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif

	ll tst = 1;
//	cin >> tst;
	while (tst--)
		{
			solve();
		}
	return 0;
}
