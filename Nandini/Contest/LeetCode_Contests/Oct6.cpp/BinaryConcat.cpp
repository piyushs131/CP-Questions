#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:
    int maxGoodNumber(vector<int>& nums) 
    {
        vector<string> binStrs;
        for (int num : nums) {
            binStrs.push_back(bitset<32>(num).to_string());
            binStrs.back().erase(0, binStrs.back().find_first_not_of('0'));
        }
        
        sort(binStrs.begin(), binStrs.end(), [](const string& a, const string& b) 
        {
            return a + b > b + a;
        });
        
        string concat = binStrs[0] + binStrs[1] + binStrs[2];
        
        return bitset<64>(concat).to_ullong();
    }
};
