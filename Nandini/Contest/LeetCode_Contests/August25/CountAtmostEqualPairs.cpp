#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canSwap(int i, int j, vector<int> &nums) {
        string s1 = to_string(nums[i]);
        string s2 = to_string(nums[j]);

        while (s1.length() < s2.length()) s1 = '0' + s1;
        while (s2.length() < s1.length()) s2 = '0' + s2;

        if (s1 == s2) {
            return true;
        }

        vector<int> diff;
        for (int k = 0; k < s1.size(); ++k) {
            if (s1[k] != s2[k]) {
                diff.push_back(k);
            }
        }

        if (diff.size() == 2) {
            swap(s1[diff[0]], s1[diff[1]]);
            if (s1 == s2) {
                return true;
            }
        }

        return false;
    }

    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (canSwap(i, j, nums)) {
                    count++;
                }
            }
        }
        return count;
    }
};
