#include<bits/stdc++.h>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        int i;
        int maxiDeadLine =INT_MIN;
        for(i=0 ; i<n ; i++)
        {
            maxiDeadLine =  max(maxiDeadLine,arr[i].dead);
        }
        
        vector<int> schedule(maxiDeadLine+1,-1);
        
        int count =0,profit=0;
        for(int i=0 ; i<n ; i++)
        {
            int currProfit = arr[i].profit;
            int id = arr[i].id;
            int deadline = arr[i].dead;
            
            for(int j=deadline ; j>0 ;j --)
            {
                if(schedule[j]==-1)
                {
                    count++;
                    profit+= currProfit;
                    schedule[j] = id;
                    break;
                }
            }
        }
        return {count,profit};
    } 
};
