#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int l1,l2,r1,r2;
    cin >> l1 >>  r1 >> l2 >> r2 ;
    ll l = max(l1,l2), r = min(r1,r2);
    if(r<l)
    {
        cout <<1 << endl;
        return;
    }

    ll ans = r-l+1;
    if(min(l1,l2)<l) ans++;
    if(max(r1,r2)>r) ans++;
    cout << ans-1 << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
