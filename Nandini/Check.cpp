#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) begin(x), end(x)
void solve() 
{
    int n ;
    cin >> n;
    vector<int> arr(n);
    for(int i=0 ; i<n ; i++) cin >> arr[i];
   map<int,int> mp;
   int ans =0;
   for(auto it :  arr)
   {
     mp[it]++;
     if(ans<mp[it]) ans = mp[it];
   }
   cout << n-ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
