#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
	int n;
	cin >> n;
	int ct1 = 0, ct2 = 0, ct3 = 0;
	int id1[] = {0}, id2[] = {0}, id3[] = {0};
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			if (a == 1)
				{
					ct1++;
					id1[x] = i + 1;
					x++;
				}
			else if (a == 2)
				{
					ct2++;
					id2[y] = i + 1;
					y++;
				}
			else
				{
					ct3++;
					id3[z] = i + 1;
					z++;
				}
		}
	cout << ct1 << ct2 << ct3 << "\n";
	if (ct1 == 0 || ct2 == 0 || ct3 == 0)
		{
			cout << 0;
			return;
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
			if (id1[k] != 0 && id2[k] != 0 && id3[k] != 0)
				{
					cout << id1[k] << " " << id2[k] << " " << id3[k];
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
