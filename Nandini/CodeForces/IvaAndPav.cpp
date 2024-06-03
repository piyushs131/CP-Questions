#include <bits/stdc++.h>
using namespace std;
 
class SegmentTree {
private:
    vector<int> tree;
    int n;
 
    void buildTree(vector<int>& arr, int start, int end, int node) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(arr, start, mid, 2 * node + 1);
            buildTree(arr, mid + 1, end, 2 * node + 2);
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
        }
    }
 
    int queryTree(int start, int end, int l, int r, int node) {
        if (r < start || end < l) {
            return INT_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftQuery = queryTree(start, mid, l, r, 2 * node + 1);
        int rightQuery = queryTree(mid + 1, end, l, r, 2 * node + 2);
        return leftQuery & rightQuery;
    }
 
public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        buildTree(arr, 0, n - 1, 0);
    }
 
    int query(int l, int r) {
        return queryTree(0, n - 1, l, r, 0);
    }
};
 
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
 
    SegmentTree segTree(arr);
 
    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;
 
        int low = l, high = n - 1, result = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (segTree.query(l, mid) >= k) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
 
        if (result == -1) cout << -1 << " ";
        else cout << result + 1 << " ";
    }
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}
