#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n,q;
	cin >> n >> q;
	string a ,b;
	cin >> a >> b;
	while(q--)
	{
		int a1,a2;
		cin >> a1 >> a2;
		a1--,a2--;
		map<int,int> mp;
		int ans =0;
		for(int i=a1 ; i<=a2 ; i++)
		{
			mp[a[i]-'0'-49]++;
			mp[b[i]-'0'-49]--;
		}
		for(auto it : mp)
		{
			// cout << it.first << " " << it.second << endl;
			if(it.second!=0) ans++;
		}
		cout << ans/2 << endl;
	}

}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
