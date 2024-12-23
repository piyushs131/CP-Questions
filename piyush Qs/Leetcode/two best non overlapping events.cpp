two best non overlapping events
class Solution {
public:

    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
        {
            if(a[1] == b[1])

            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int findnext(int i, vector<vector<int>>& events)
    {
        int left = i+1, right = events.size()-1;
        int ans = right+1;

        if(left >= right+1)
            return ans;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(events[i][1] < events[mid][0])
            {
                ans = min(ans, mid);
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return ans;
    }
    int helper(int i, vector<vector<int>>& events, vector<int>& prefix)
    {
        if(i>=events.size())
            return 0;
        int next_max = findnext(i, events);
        int take = events[i][2];
        if(next_max < events.size())
            take += prefix[next_max];
        int nottake = helper(i+1,events, prefix);
        return max(take, nottake);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), compare);
        int n =  events.size();
        vector<int> prefix(n, 0);
        prefix[n-1] = events[n-1][2];
        for(int i=n-2;i>=0;i--)
        {
            prefix[i] = max(prefix[i+1], events[i][2]);
        }
        return helper(0, events, prefix);
        // return 0;
    }
};