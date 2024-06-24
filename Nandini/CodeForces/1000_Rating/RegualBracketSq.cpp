#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    string s ;
    cin >> s;
    if(s[0]==')' || s[s.size()-1]=='(')
    cout << "NO" << endl;
    else if(count(s.begin(),s.end(),'?')%2==0)
    cout << "YES" << endl;
    else 
    cout << "NO" << endl;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
}