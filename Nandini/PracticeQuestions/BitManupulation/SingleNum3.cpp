#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        long long xorr = 0;  
        for(auto it : nums) xorr = xorr ^ it;

        long long msb = (xorr & (xorr - 1)) ^ xorr;
        long long x = 0, y = 0;  
        for(auto it : nums)
        {
            if(msb & it) x ^= it;
            else y ^= it;
        }
        return {static_cast<int>(x), static_cast<int>(y)};  
    }
};
