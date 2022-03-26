class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return search(nums,target,0,n-1);
    }
    
    int search(vector<int> &nums,int target,int left,int right){
        if(left>right)
            return -1;
        int mid = left+(right-left)/2;
        if(target==nums[mid])
            return mid;
        else if(target>nums[mid]){
            return search(nums,target,mid+1,right);
        }
        else
            return search(nums,target,left,mid-1);
    }
};