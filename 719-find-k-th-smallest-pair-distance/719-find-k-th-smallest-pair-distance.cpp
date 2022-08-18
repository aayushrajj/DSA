class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums.back() - nums.front();
        
        while(low<high){
            int mid = low + (high-low)/2;
            if(check(nums,mid,k))
                high = mid;
            else
                low = mid+1;
        }
        
        return high;
    }
    
    bool check(vector<int>& nums,int diff,int k){
        int n = nums.size();
        int count=0,i=0,j=0;
        while(i<n || j<n){
            while(j<n && nums[j]-nums[i] <= diff)
                j++;
            
            count += j-i-1; //count pairs for current i
            i++;
        }
        
        return count>=k;
    }
};