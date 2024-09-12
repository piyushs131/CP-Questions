#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        int XOR = 0;
        for(int i=0 ; i<n ; i++)
        XOR^=arr[i];
        
        int last_set_bit_num = XOR & ~(XOR-1);
        
        long long int x=0,y=0;
        for(int i=0 ; i<n ; i++)
        {
            if(arr[i] & last_set_bit_num)
            {
                x^=arr[i];
            }
            else 
            {
                y^=arr[i];
            }
        }
        return x > y ? vector<long long int>{x, y} : vector<long long int>{y, x};
    }
};
