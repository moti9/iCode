#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		{
			ll n, x;
			cin >> n >> x;
			ll a[n];
			bool b[n] = {0};
			for (int i = 0; i < n; i++)
				{
					cin >> a[i];
				}
			ll ans_no = INT_MIN, ans_op = 0;
			for (int i = 0; i < n; i++)
				{
					ll sum = 1;
					ll op = 1;
					ll count = 0;
					if (b[i] == 0)
						{
							ll xr = a[i] ^ x;
							b[i] = 1;
							for (int j = i + 1; j < n; j++)
								{
									if (a[j] == xr && b[j] == 0)
										{
											b[j] = 1;
											sum++;
											count++;
										}
									if (a[j] == a[i] && x != 0)
										{
											op++;
											sum++;
											b[j] = 1;
										}
								}
						}
					if (sum > ans_no)
						{
							ans_no = sum;
							if (count < op)
								{
									ans_op = count;
								}
							else if (x != 0)
								{
									ans_op = op;
								}
						}
				}
			cout << ans_no << " " << ans_op << endl;
		}
	return 0;
}
