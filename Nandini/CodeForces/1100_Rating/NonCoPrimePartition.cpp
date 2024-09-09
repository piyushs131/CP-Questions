#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<int>
void solve()
{
	int n;
	cin >> n; 
	if(n<=2) cout << "No" ;
	else 
	{
		cout << "Yes" << endl;
		cout << n-1 << " ";
		for(int i=1 ; i<n ; i++) cout << i << " ";
		cout << endl << 1 << " " << n ;
	}
}

int main() {
	//  int t;
	//  cin >> t;
	//  while(t--) solve();
	solve();
}

