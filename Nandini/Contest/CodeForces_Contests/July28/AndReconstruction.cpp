#include <bits/stdc++.h>
using namespace std;
#define lli long long int
void solve()
{
	int n;
	cin >> n;
	vector<lli> v(n-1);
	for(int i=0 ;i <n-1 ; i++) cin >> v[i];

	vector<int> ans(n,0);
	for(int i=0 ; i<n-1 ; i++)
	{
		ans[i] |= v[i];
		ans[i+1] |= v[i];
	}

	for(int i=0 ; i<n-1 ; i++)
	{
		if(v[i]!=(ans[i]&ans[i+1])){
			cout << -1 << endl;
			return;
		}
	}
	for(auto it : ans)
	cout << it <<" ";
	cout <<endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
