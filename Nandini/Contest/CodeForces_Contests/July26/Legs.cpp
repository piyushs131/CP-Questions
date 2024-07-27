#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n,count=0;
	cin >> n;
	while(n>=4)
	{
		count++;
		n-=4;
	}
	while(n>=2)
	{
		count++;
		n-=2;
	}
	cout << count << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
