#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin >> n;
    map<int,int> mp;
    for(int i=0 ; i <n ; i++)
    {
        cin >> k;
        mp[k]++;
    }

    if(mp.size()>=3)
    {
        cout << n ;
        return;
    }
    else if(mp.size()==1)
    {
        cout << 1 ;
        return;
    }
    else 
    {
        cout << (n-2)/2 +2;
        return;
    }
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