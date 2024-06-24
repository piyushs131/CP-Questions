#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   ll n;
   cin >> n;
   if(n>14 && n%14>=1 && n%14<=6)cout << "Yes" << endl;
   else cout << "No" << endl;    
}
int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}