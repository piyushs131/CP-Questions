#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve() {
      int n;
      cin>>n;
      int a = 0, b = 0;
      int flag = 0;
      int ten = 1;
      string k = to_string(n);
      int len = k.size();
      for (int i = 0; i < len; i++)
      {
            int x = k[i] - '0';
            if (x % 2 == 0)
            {
                  a *= 10;
                  b *= 10;
                  a += x / 2;
                  b += x / 2;
            }
            else{
                  if(flag == 0){
                        a *= 10;
                        b *= 10;
                        a += (x / 2) + 1;
                        b += x / 2;
                  }
                  else{
                        a *= 10;
                        b *= 10;
                        a += x / 2;
                        b += (x / 2) + 1;
                  }
                  flag = 1 - flag;
            }
            n /= 10;
      }
      cout << a << " " << b << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
