#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<int>
void solve()
{
	int n;
	cin >> n;
	v arr(n);
	for(int i=0 ; i<n ; i++) cin >> arr[i];
	int count =2;
	int i=0,j=n-1;
	int c1=0,c2=0;
	int ans =0;
	c1 = arr[0],c2=arr[n-1];
	while(i<j)
	{
		if(c1<c2)
		{
			i++;
			c1+=arr[i];
		}
		else if(c2<c1) {
			j--;
			c2+=arr[j];
		}
		else 
		{
           ans = max(ans,count);
           i++;
		   c1+= arr[i];
		}
		count++;
	}

	cout << ans << endl;
}

int main() {
	 int t;
	 cin >> t;
	 while(t--) solve();
}

