#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int maxi =0;
	for(int i=0 ; i<n ; i++) {
		cin >> v[i];
	    maxi = max(maxi,v[i]);
	}

	cout << n << endl;
	for(int i=0 ; i<n ; i++)
	{
		ll deg = 1;
		while(deg<v[i])
		deg*=2;
		
		cout << i+1 << " " << deg-v[i] << endl; 
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
