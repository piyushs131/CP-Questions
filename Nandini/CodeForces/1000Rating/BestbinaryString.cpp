#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    string s;
    cin >> s;
    int ind = 0,st=0;
    while (ind<s.size() && s[ind] == '?')
    ind++;

    if(ind==s.size())
    {
        while(st<s.size() && s[st]=='?')
        {
            s[st] = '0';
            st++;
        }
        cout << s ;
        return;
    }

    while(s[st]=='?')
    {
      s[st] = s[ind]; 
      st++;
    }
    st = ind;
    for (int i = st; i < s.size(); i++)
    {
        if(s[i]=='?')
        s[i] = s[ind];
        else 
        {
            ind = i;
        }
    }
    cout << s ;
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