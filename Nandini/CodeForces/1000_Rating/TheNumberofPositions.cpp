#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   int n,a,b;
   cin >> n >> a >> b;
   if(n-a-1 <= b)
   cout << n-a ;
   else 
   {
     cout << b+1 ;
   }
}
int main()
{
    solve();
}