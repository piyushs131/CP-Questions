#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   int n;
   cin >> n;
   vector<int> d(n);
   vector<int> a(n);
   for(int i=0 ; i<n ; i++)
   cin >> d[i];

   a[0] = d[0];
   for(int i=1 ; i<n ;i ++)
   {
      if(a[i-1]-d[i]>=0 && a[i-1]+d[i]!=a[i-1]-d[i])
      {
        cout << -1 << endl;
        return;
      }
      else 
      {
         a[i] = a[i-1]+d[i];
      }
   }
   for(int i=0 ; i<n ;i ++)
   cout << a[i] << " ";
   cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
