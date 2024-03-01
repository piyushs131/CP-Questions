#include<bits/stdc++.h>
using namespace std;
int assignCookie(vector<int> &greed, vector<int> &size) 
{
	sort(greed.begin(),greed.end());
	sort(size.begin(),size.end());
	int i,j=0,g = greed.size(),s = size.size();
	int ans =0;
	for(int i=0 ; i<g ; i++)
	{
		while(j<s && greed[i]>size[j])
		j++;

		if(j==s)
		break;

		if(j<s)
		{
			ans++;
			j++;
		}
	}
	return ans;
}
