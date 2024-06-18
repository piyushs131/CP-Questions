#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n;
    cin >> n;
    ll pos=0;
    ll k,ans=0;
    for(int i=0 ; i<n ; i++)
    {
        cin >> k;
        if(k<0)
        {
            if(pos>abs(k))
            {
                pos-=abs(k);
            }
            else 
            {
                ans+=abs(k)-pos;
                pos =0;
            }
        }
        else 
        {
            pos+=k;
        }

    }
    cout << ans << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
}