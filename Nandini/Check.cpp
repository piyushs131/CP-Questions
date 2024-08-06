#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
   int a1,a2,b1,b2;
   cin >> a1 >> a2 >> b1 >> b2;
   int count1 =0;
   if(a1>b1) count1++;
   if(a1>b2) count1++;
   if(a2>b1) count1++;
   if(a2>b2) count1++;

   if(count1==3)
   {
    cout << 2 << endl;
   }
   else if(count1==1 || count1==2 || count1==0) {
    cout << 0 << endl;
   }
   else cout << 4 << endl;
}
int main() 
{
    int t;
    cin >> t;
    while(t--)
    solve();
}
