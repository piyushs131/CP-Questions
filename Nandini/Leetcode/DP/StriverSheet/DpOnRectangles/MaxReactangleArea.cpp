#include <bits/stdc++.h>
using namespace std;
int largestArea(vector<int> &histo)
{
	int n= histo.size();
	stack<int> st;
	int area=0;
	for(int i=0 ;i<=n ; i++)
	{
		while(!st.empty() && (i==n || histo[st.top()]>=histo[i]))
		{
            int height = histo[st.top()];
			st.pop();
			int width;
			if(st.empty()) width = i;
			else 
			width = i-st.top()-1;

			area = max(area,width*height);
		}
		st.push(i);
	}
	return area;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
	int area = 0;
	vector<int> height(m,0);
	for(int i=0 ; i<n ;i++)
	{
		for(int j=0 ; j<m ; j++)
		{
          if(mat[i][j]==1) height[j]++;
	    	else height[j] =0;
		}
        int Maxarea = largestArea(height);
		area =max(area,Maxarea);
	}
	return area;

}