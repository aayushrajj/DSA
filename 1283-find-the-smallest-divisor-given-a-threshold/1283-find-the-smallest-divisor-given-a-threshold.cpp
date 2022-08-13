class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        
        while(low<high){
            int mid = low + (high-low)/2;
            
            int sum = helper(nums,mid);
            if(sum>threshold)
                low = mid+1;
            else
                high = mid;
        }
        
        return high;
    }
    
    int helper(vector<int> &nums,int div){
        int total = 0;
        
        for(int i=0;i<nums.size();i++){
            int quo = nums[i]/div + (nums[i]%div==0 ? 0 : 1);
            total += quo;
        }
        
        return total;
    }
};