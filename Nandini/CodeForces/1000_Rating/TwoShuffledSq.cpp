#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
   int n,k;
   cin >> n;
   map<int,int> mp;
   for(int i=0 ; i<n ; i++)
   {
     cin >> k;
     mp[k]++;
     if(mp[k]>2)
     {
        cout << "NO" << endl;
        return;
     }
   }
   vector<int> a1;
   cout << "YES" <<endl;
   for(auto it : mp)
   {
     a1.push_back(it.first);
   }
   vector<int> a2;
   for(auto it: mp)
   {
    if(it.second==2)
    {
        a2.push_back(it.first);
    }
   }
   reverse(a2.begin(),a2.end());
   cout << a1.size()<< endl;
   for(auto it : a1)
   cout << it << " ";
   cout << "\n" << a2.size() << endl;
   if(a2.size()==0)
   {
    cout << endl;
    return;
   }
   for(auto it : a2)
   cout << it << " ";
}
int main()
{
    solve();
}