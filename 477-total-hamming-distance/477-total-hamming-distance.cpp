class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i=0;i<32;i++){
            int zeros=0,ones=0;
            for(int j=0;j<n;j++){
                if(nums[j]&1)
                    ones++;
                else
                    zeros++;
                nums[j] >>= 1;
            }
            
            if(ones==n || zeros==n)
                sum += 0;
            else
                sum += (zeros*ones);
        }
        
        return sum;
    }
};