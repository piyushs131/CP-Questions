#include <bits/stdc++.h>
using namespace std;
#define lli long long int
class Solution {
public:
    bool isPossible(int n, int index, int maxSum, int target) {
        long long sum = target;
        
        // Sum of elements to the left of the index
        if (target > index) {
            sum += (long long)(target - 1 + target - index) * index / 2;
        } else {
            sum += (long long)target * (target - 1) / 2 + (index - target + 1);
        }
        
        // Sum of elements to the right of the index
        if (target > n - index - 1) {
            sum += (long long)(target - 1 + target - (n - index - 1)) * (n - index - 1) / 2;
        } else {
            sum += (long long)target * (target - 1) / 2 + (n - index - target);
        }
        
        return sum <= maxSum;
    }

    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum;
        int result = 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPossible(n, index, maxSum, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
};
