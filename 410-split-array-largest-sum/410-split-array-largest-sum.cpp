class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int low =*max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        
        while(low<high){
            int mid = low + (high-low)/2;
            if(valid(nums,m,mid))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
    
    bool valid(vector<int> &nums,int m,int mid){
        int count=1;
        int sum = 0;
        for(auto num : nums){
            sum += num;
            if(sum>mid){
                count++;
                sum = num;
                if(count>m)
                    return false;
            }  
        }
        return true;
    }
};