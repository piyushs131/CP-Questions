#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   int n;
   cin >> n;
   vector<int> shops(n);
   for(int i=0 ;i <n ;i ++)
   cin >> shops[i];

   int q;
   cin >> q;
   vector<int> coins(q);
   for(int i=0 ; i<q ;i ++)
   cin >> coins[i];

   sort(shops.begin(),shops.end());
   for(int i=0 ; i<q ; i++)
   {
       int ans = upper_bound(shops.begin(), shops.end(), coins[i]) - shops.begin();
       cout << ans << endl;
   }
}

int main()
{
    solve();
    return 0;
}
