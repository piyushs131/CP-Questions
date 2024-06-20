#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   ll n,a,b;
   cin >> n >> a >> b;
   if(n<a)
   {
    cout <<1 << endl;
    return;
   }
   if(a<=b)
   {
     float num = (float)n/(float)a;
     if(n/a <num)
     cout << n/a +1 << endl;
     else 
     cout << n/a << endl;
     return;
   }
   else 
   {
    cout << 1 << endl;
    return;
   }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    solve();
}