#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    ll k;
    while (t--)
    {
        ll n, count = 0;
        vector<ll> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            v.push_back(k);
        }
        if (v.size() == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        int st=0;
        while( st+1 < n && v[st]==v[st+1])
        st++;

        if (st+1>=n || v[st] < v[st+1])
            count++;   

        for (int i = st+1; i < n; i++)
        {
            if (v[i] < v[i - 1])
            {
                while (i+1<n && v[i] == v[i + 1])
                    i++;

                if (i+1<n && v[i] < v[i + 1])
                    count++;
                else if(i+1>=n)
                count++;    
            }
        }
        if(count==1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
