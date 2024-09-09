#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define v vector<int>
bool solve()
{
	int n;
    cin >> n;
	vector<int> arr(n);
	for(int i=0 ;i <n ; i++) cin >> arr[i];

	for(int i=0 ; i<n-1 ; i++)
	{
		if(arr[i]&1!=0){
			if(arr[i+1]>0)
			{
				arr[i+1]--;
				if(arr[i+1]==0) i++;
			}

			else return false;
		}
	}
    if(arr[n-1]%2!=0) return false; 
	return true;
}

int main() {
	 if(solve())cout << "YES" ;
	 else cout << "NO";
}

