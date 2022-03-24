class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(q.front() == i-k)
                q.pop_front();
            while(q.size()>0 && nums[q.back()]<nums[i])
                q.pop_back();
            q.push_back(i);
            if(i+1-k>=0)
                res.push_back(nums[q.front()]);
        }
        return res;
    }
};