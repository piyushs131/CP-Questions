#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll n;
    cin >> n;
    int k;
    vector<ll> even;
    vector<int> odd;
    for(int i=0 ;i <n ; i++) {
        cin >> k;
        if(k%2!=0) odd.push_back(k);
        else even.push_back(k);
    }

   if(odd.size()==0 || even.size()==0) {
    std::cout << 0 << endl;
    return;
   }

   sort(odd.begin(),odd.end());
   sort(even.begin(),even.end());

   ll count =even.size();
   ll maxi = odd.back();
   for(auto it : even)
   {
       if(it>maxi) {
        count++;
        break;
       }
       maxi+=it;
   }
   std::cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
