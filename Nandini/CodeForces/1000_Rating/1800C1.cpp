#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k,ans=0;
        cin >> n;
        priority_queue<ll> pq;
        for(ll i=0 ; i<n ; i++)
        {
            cin >> k;
            if(k!=0)
            pq.push(k);
            else 
            {
                if(!pq.empty())
                {
                ans+= pq.top(); pq.pop();
                }
            }
        }
        cout << ans << endl;
    }
}