#include <bits/stdc++.h>
using namespace std;
#define ll long long

int smallest(vector<int> &a, int l, int r)
{
	int sm = INT_MAX;
	for (int i = l; i <= r; i++)
	{
		if (sm > a[i])
			sm = a[i];
	}
	return sm;
}

int largest(vector<int> &a, int l, int r)
{
	int lg = INT_MIN;
	for (int i = l; i <= r; i++)
	{
		if (lg < a[i])
			lg = a[i];
	}
	return lg;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	int l = 0, r = n - 1;

	while (l < n && a[l] == b[l])
		l++;
	while (r >= 0 && a[r] == b[r])
		r--;

	while (l > 0 && b[l - 1] <= b[l])
		l--;
	while (r < n - 1 && b[r + 1] >= b[r])
		r++;

	cout << l + 1 << " " << r + 1 << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
