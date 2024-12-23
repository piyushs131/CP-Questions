#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<int> a(6,0);
    vector<int> b(6,0);
    int tmp;

    for(int i=0 ;i <n ; i++)
    {
        cin >> tmp;
        a[tmp]++;
    }

    for(int i=0 ; i<n ; i++)
    {
        cin >> tmp;
        b[tmp]++;
    }

    ll ans =0;
    for(int i=1 ; i<=5 ;i ++)
    {
        if((a[i] + b[i]) % 2 != 0) {
			cout << -1 ;
			return ;
		}
         tmp = (a[i] + b[i]) >> 1;
		tmp = max(a[i], b[i]) - tmp;
		ans += tmp;
    }
    cout << ans/2;
}

int main()
{
    solve();
    return 0;
}
