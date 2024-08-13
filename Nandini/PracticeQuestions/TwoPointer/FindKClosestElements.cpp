#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findClosed(vector<int>& arr, int x) {
        int l = 0, u = arr.size() - 1, mid;
        while (l < u) {
            mid = l + (u - l) / 2;
            if (arr[mid] == x) return mid;
            else if (arr[mid] > x) u = mid;
            else l = mid + 1;
        }
        if (l > 0 && abs(arr[l-1] - x) <= abs(arr[l] - x)) {
            return l - 1;
        }
        return l;
    }

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (k == 0) return {};
        vector<int> ans;
        int closedIndex = findClosed(arr, x); 
        ans.push_back(arr[closedIndex]);
        k--;
        int r = closedIndex + 1, l = closedIndex - 1;

        while (k > 0) {
            if (l < 0) {
                ans.push_back(arr[r++]);
            } else if (r >= arr.size()) {
                ans.push_back(arr[l--]);
            } else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                ans.push_back(arr[l--]);
            } else {
                ans.push_back(arr[r++]);
            }
            k--;
        }

        sort(ans.begin(), ans.end());
        return ans; 
    }
};
