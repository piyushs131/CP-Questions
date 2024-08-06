#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
   int n,s,m,a,b;
   cin >> n >> s >> m;
   vector<pair<int,int> > v;
   for(int i=0 ; i<n ; i++){
    cin >> a >> b;
    v.push_back({a,b});
   }
   if(n==0)
   {
     if(m>=s){
        cout << "YES" << endl;
     }
     else cout << "NO" << endl;

     return;
   }

   int last =0;
   for(auto it : v)
   {

     if(it.first-last >=s)
     {
        cout << "YES" << endl;
        return;
     }
      last = it.second;
   }
   if(m-last>=s) {
    cout << "YES" << endl;
   }
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
