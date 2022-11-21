#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
	int n;
	cin >> n;
	int a[n];
	int ct1 = 0, ct2 = 0, ct3 = 0;
	for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			if (a[i] == 1)
				ct1++;
			else if (a[i] == 2)
				ct2++;
			else
				ct3++;
		}

	if (ct1 == 0 || ct2 == 0 || ct3 == 0)
		{
			cout << 0;
			return;
		}
	vector<int> v1, v2, v3;
	for (int i = 0; i < n; i++)
		{
			if (a[i] == 1)
				v1.push_back(i + 1);
			else if (a[i] == 2)
				v2.push_back(i + 1);
			else
				v3.push_back(i + 1);
		}
	int w = 0;
	while (ct1 > 0 && ct2 > 0 && ct3 > 0)
		{
			ct1--;
			ct2--;
			ct3--;
			w++;
		}
	cout << w << "\n";
	int k = 0;
	while (w--)
		{
			if (v1[k] != 0 && v2[k] != 0 && v3[k] != 0)
				{
					cout << v1[k] << " " << v2[k] << " " << v3[k];
				}
			cout << "\n";
			k++;
		}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif

	ll test = 1;
	//cin>>test;
	while (test--)
		{
			solve();
		}
	return 0;
}
