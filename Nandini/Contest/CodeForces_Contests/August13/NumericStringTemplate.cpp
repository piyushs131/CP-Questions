#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check(vector<ll> &v,string s,int n)
{
    unordered_map<int,char> mp1;
    unordered_map<char,int> mp2;
    for(int i=0 ; i<n ; i++)
    {
        if(mp1[v[i]]==0)
        mp1[v[i]]=s[i];
        else if(mp1[v[i]]!=s[i]) return false;

        if(mp2[s[i]]==0)
        mp2[s[i]] = v[i];
        else if(mp2[s[i]]!=v[i]) return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0 ; i<n ; i++) cin >> v[i];
    int m;
    cin >> m;
    string s;
    while(m--)
    {
      cin >> s;
      if(s.size()==n && check(v,s,n))
      cout << "YES" << endl;
      else cout << "NO" << endl;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
