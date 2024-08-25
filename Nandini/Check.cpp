#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve() 
{
	int n; 
    cin >> n;
	if(n % 2 == 1) 
    {
		int r = n;
		int l = 1;
		for(int i = 1; i <= n; i++) {
			if(i % 2 == 1) {
				cout << r << " ";
				r--;
			} else {
				cout << l << " ";
				l++;
			}
		}
		cout << endl;
	} 
    else 
    {
		cout << -1 << endl;
	}
}

int main() {
	int t; 
    cin >> t;
	while(t--) solve();
}

