#include<bits/stdc++.h>
using namespace std;
int main()
{
   int T;
   int n,x,k,sum,i;
   cin >> T;
   while(T--)
   {
     cin >> n >> x;
     int a[n];
     for( i=0 ; i<n ; i++)
     cin >> a[i];
     int ans = a[0];
     for( i=1 ; i<n ; i++)
     ans=max(ans,a[i]-a[i-1]);
     
     ans=max(ans,2*(x-a[n-1]));
     cout << ans << endl;
   }
}
