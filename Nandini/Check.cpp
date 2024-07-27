#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	ll n,x,ans=0;
    cin >> n >> x;
    for (int a = 1; a <= x && a<=n; ++a) {
       for(ll b = 1; a*b<=n && a+b<=x ; b++)
       {
          const ll c1 = x-a-b,c2 = max(0ll,n-a*b)/(a+b);
          ans+=min(c1,c2);
       }
    }

	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
