#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int s = 0, e = queries.size(), ans = -1;
        vector<int> original_nums = nums;

        while (s <= e) {
            int m = (s + e) / 2;
            vector<int> change(n + 1, 0);
            
            // Apply first m queries
            for (int k = 0; k < m; k++) {
                int a = queries[k][0];
                int b = queries[k][1];
                int val = queries[k][2];

                change[a] -= val;
                if (b + 1 < n) {
                    change[b + 1] += val;
                }
            }

            nums = original_nums;
            int diff = 0;
            bool pos = true;

            // check if all 0
            for (int i = 0; i < n; i++) {
                diff += change[i];
                nums[i] += diff;
                if (nums[i] > 0) {
                    pos = false;
                    break;
                }
            }

            if (pos) {
                ans = m;
                e = m - 1; // smaller number of queries
            } else {
                s = m + 1; // larger number of queries
            }
        }

        return ans;
    }
};
