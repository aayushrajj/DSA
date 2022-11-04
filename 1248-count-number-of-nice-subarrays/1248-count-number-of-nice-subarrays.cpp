class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;
        int total=0,ans=0,count=0;
        
        while(j<n){
            if(nums[j]&1){
                count++;
                if(count>=k){
                    ans = 1;
                    while(nums[i]%2==0){
                        ans++;
                        i++;
                    }
                    i++; // on the left of window , we dont stay at that last odd but move a step right from there as we already calculated our count till that odd we encountered
                    total += ans;
                }
            }
            else if(count>=k)
                total += ans;
            j++;
        }
        return total;
    }
};