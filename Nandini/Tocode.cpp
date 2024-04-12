#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<int,queue<int> > freq;
        vector<int> v(n),ans(n);
        bool valid = true;
        for(int i=0 ; i<n ; i++)
        {
            cin >> v[i];
            freq[v[i]].push(i);
        }
        for(int i=0 ; i<n ; i++)
        {
            if(freq[v[i]].size()<2)
            {valid = false;break;}
        }
        if(!valid)
        {
            cout << -1 << endl;
        }
        else 
        {
            for(auto e : freq)
            {
                int val = freq[e.first].front();
                freq[e.first].pop();
                freq[e.first].push(val);
            }
            for(int i=0 ;i <n ; i++)
            {
               cout << freq[v[i]].front()+1 << " ";
               freq[v[i]].pop();
            }
            cout << endl;
        }
    }
}