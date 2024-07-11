#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() 
{
   int x,y;
   cin >> x >> y;
   int t = x;
   cout << 2*(x-y) << endl;
   while(t!=y)
   {
    cout << t << " "; 
    t--;
   } 
   while(y!=x)
   {
     cout << y << " ";
     y++;
   }
   cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
