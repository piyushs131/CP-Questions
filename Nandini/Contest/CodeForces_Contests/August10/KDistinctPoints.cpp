#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
   int x,y,k;
   cin >> x >> y >> k;
   if(k%2!=0) {
    k--;
    cout << x << " " << y << endl;
   }

   int p1=y+1,p2=y-1;
   while(k!=0)
   {
    cout << x << " " << p1 << endl;
    cout << x << " " << p2 << endl;
    p1++;
    p2--;
    k-=2;
   }
}
int main() 
{
    int t;
    cin >> t;
    while(t--)
    solve();
}
