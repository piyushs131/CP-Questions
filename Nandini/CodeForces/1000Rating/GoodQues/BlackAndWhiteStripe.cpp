#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,k,a=0,maxi=0,max_ind=-1;
    bool flag = 1;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> v(n+1);
    v[0] = 0;
    for(int i=0 ; i<n ; i++)
    {
        v[i+1] = v[i];
        if(s[i]=='W')
        v[i+1]++;
    }
    int ans = n;
    for(int i=0 ; i<=n-k ; i++)
    {
      ans = min(ans,v[i+k]-v[i]);
    }
    cout << ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}