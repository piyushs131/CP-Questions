#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    ll ans =0,mini = INT_MAX,ct=0,k;
    for(int i=0 ; i<n ; i++)
    {
       cin >> k; 
       ans+= abs(k);
       if(k<0) ct++;
       mini = min(abs(k),mini);
    }
    if(ct%2) cout << ans-2*mini << endl;
    else 
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
