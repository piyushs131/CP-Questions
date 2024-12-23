#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    ll n;
    cin >> n;
    vector<ll> pref(n+1,0);
    for(ll i=1 ; i<=n ; i++){
        ll k;
        cin >> k;
        pref[i] = k+pref[i-1]; 
    }
    string s;
    cin >> s;
    s = '.' + s;

    ll left =0 ,right = n, ans =0;
    while(left<right)
    {
        while(left<right && s[left]!='L') left++;
        while(left< right && s[right]!='R') right--;

        if(right<=left) break;
        ans+= pref[right] - pref[left-1];
        left++;
        right--;
    }
    cout << ans << endl;
}
int main()
{
    ll t;
    cin >> t;
    while (t--){
        solve();
    }
}
