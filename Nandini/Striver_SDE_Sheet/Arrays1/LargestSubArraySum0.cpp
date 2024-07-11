#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int maxLen(vector<int>& arr, int N) 
    {
        unordered_map<int, int> presum;
    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i];

        if (sum == 0) {
            max_len = i + 1;
        }

        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        } else {
            presum[sum] = i;
        }
    }

    return max_len;
    }
};
