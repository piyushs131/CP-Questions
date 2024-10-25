#include<bits/stdc++.h>
using namespace std;
void solve(){
 int n;
 cin >> n;
 string s;
 cin >> s;
 int ct=0;
 for(int i=0 ;i <n ; i++){
  if(s[i]=='1') ct++;
 }
 if(ct==0) cout << n << endl;
 else if(ct%2==0) cout << 0 << endl;
 else cout << 1 << endl;
}
int main(){
  int t ;
  cin >> t;
  while(t--) solve();
}