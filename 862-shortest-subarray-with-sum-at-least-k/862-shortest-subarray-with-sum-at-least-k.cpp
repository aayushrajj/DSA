class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> sum(n,0);
        sum[0] = nums[0];
        deque<int> q;
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            if(i>0)
                sum[i] = sum[i-1]+nums[i];
            if(sum[i]>=k)
                res = min(res,i+1);
            while(q.size()>0 && sum[i]-sum[q.front()] >= k)
                res = min(res,i-q.front()) , q.pop_front();
            while(q.size()>0 && sum[i]<=sum[q.back()])
                q.pop_back();
            q.push_back(i);
        }
        return res==INT_MAX ? -1 : res;
    }
};