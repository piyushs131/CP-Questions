#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
	vector<int>AllPrimeFactors(int N) 
	{
	   vector<int> ans;
	   int num = pow(N,0.5);
	   for(int i=2 ;i <=num ; i++)
	   {
	       if(N%i==0)
	       {
	           //cout << "i=" << i << endl;
	           ans.push_back(i);
	           while(N%i==0)
	           {
	               N = N/i;
	           }
	       }
	   }
	   if(N!=1) ans.push_back(N);
	   return ans;
	}
};
