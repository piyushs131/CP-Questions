#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k,b,s;
        cin >> n >> k >> b >> s;
        // range in which soln should lie
        if(s<k*b || s>k*b+n*(k-1))
        cout << -1 << endl;
        else 
        {
            vector<ll> v;
            for(int i=0 ; i<n ; i++)
            {
                if(b){v.push_back(1);b--;}
                else v.push_back(0);
            }
            if(b) v[n-1]+=b;
            for(ll i=0 ; i<n ; i++)
            {
                v[i]*=k;
                s-=v[i];
            }
            if(s)
            {
                for(ll i=0 ; i<n ; i++)
                {
                    if(s>=(k-1))
                    {
                        v[i]+=k-1;  
                        s-=k-1;
                    }
                    else 
                    {
                        v[i]+=s;    
                        s=0;
                    }
                }
            }

            for(ll i=0 ; i<n ; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}