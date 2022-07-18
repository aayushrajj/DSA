class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int minCount=0,maxCount=0;
        int minVal=INT_MAX,maxVal=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxVal){
                maxCount=1;
                maxVal = nums[i];
            }
            else if(nums[i]==maxVal)
                maxCount++;
            
            if(nums[i]<minVal){
                minCount=1;
                minVal = nums[i];
            }
            else if(nums[i]==minVal)
                minCount++;
        }
        
        return ( n - (minCount+maxCount) ) < 0 ? 0 : n - (minCount+maxCount);
    }
};