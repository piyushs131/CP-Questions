#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void solve()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0 ;i <n ; i++) cin >> v[i];

	if(n==1)
	{
		cout << v[0] << endl;
		return;
	}
	int i;
	for( i=0 ; i<n-2 ; i++)
	{
		if(v[i]+v[i+1] < v[i+1]+v[i+2])
		i++;

		else
		{
			swap(v[i],v[i+2]);
			i++;
		}
	}
	cout <<v[i] << endl;
	// for( i=0 ;i<v.size() ; i++)
	// cout << v[i] << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
