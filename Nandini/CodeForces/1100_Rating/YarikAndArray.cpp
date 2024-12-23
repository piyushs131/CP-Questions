#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	ll maxSum = INT_MIN,par=0,b,sum=0;
	for(int i=0 ;i <n ; i++)
	{
		cin >> b;
		if(abs(b)%2!=par){
			sum+=b;
		}
		else 
		{
			sum = b;
		}
		if(b>sum){
			sum = b;
		}
		par = abs(b)%2;
		maxSum = max(maxSum,sum);
	}
	
	cout << maxSum << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
		solve();
}
