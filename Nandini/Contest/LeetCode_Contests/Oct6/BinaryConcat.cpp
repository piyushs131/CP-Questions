#include <bits/stdc++.h>
#include<math.h>
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
class Solution2 {
public:
    static bool cmp(const string &a, const string &b) {
        return (a + b) > (b + a);
    }

    int maxGoodNumber(vector<int>& nums) {
        vector<string> v;
        
        for (int i = 0; i < 3 && i < nums.size(); i++) {
            int n = nums[i];
            string s = "";
            // converting number into binary
            while (n > 0) {
                s = (n % 2 == 0 ? "0" : "1") + s; 
                n = n / 2;
            }

            if (s.empty()) {
                s = "0";
            }
            v.push_back(s);
        }

        sort(v.begin(), v.end(), cmp);

        string ans_binary = v[0] + v[1] + v[2];

        int ans = 0;
        for (int i = 0; i < ans_binary.size(); i++) {
            ans += (ans_binary[i] - '0') * pow(2, ans_binary.size() - 1 - i);
        }
        return ans;
    }
};

