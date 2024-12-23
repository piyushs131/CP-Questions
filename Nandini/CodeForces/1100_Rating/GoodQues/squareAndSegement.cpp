#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<int>
void solve()
{
	int n;
	cin >> n; 
	int p=sqrt(n);
    int ans=INT_MAX,flag=0;
     if(n==1){
         ans=2;
         cout<<ans<<endl;
         return ;
     }
     if(p*p==n)ans=min(2*p,ans);
     else if(p*(p+1)>=n) ans=min(p+p+1,ans);
     else ans=min(2*(p+1),ans);
     cout<<ans<<endl;
}

int main() {
	//  int t;
	//  cin >> t;
	//  while(t--) solve();
	solve();
}

