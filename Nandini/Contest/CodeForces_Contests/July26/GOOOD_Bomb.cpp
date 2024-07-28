#include <bits/stdc++.h>
using namespace std;
#define lli long long int
long long int a[200005], b[200005];
void solve()
{
	long long int n, k;
	cin >> n >> k;
	long long int i;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
		cin >> b[i];

	long long int cnt;
	long long int min, mid, max;
	min = 0;
	max = 1e9 + 1;
	while (max - min > 1)
	{
		mid = (max + min) / 2;
		cnt = 0;
		for (i = 0; i < n; i++)
			if (a[i] >= mid)
				cnt += (a[i] - mid + b[i]) / b[i];
		if (cnt < k)
			max = mid;
		else
			min = mid;
	}
	long long int ans = 0, c;
	cnt = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= max)
		{
			c = (a[i] - max + b[i]) / b[i];
			cnt += c;
			ans += c * (2 * a[i] - (c - 1) * b[i]) / 2;
		}
	}
	ans += min * (k - cnt);
	cout << ans << endl;
	return;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
