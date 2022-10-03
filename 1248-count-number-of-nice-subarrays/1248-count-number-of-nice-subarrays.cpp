class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int j =0, total =0, count =0;
        int odd=0;
        for(int i=0;i<n;i++){
            if(nums[i]&1){
                odd++;
                if(odd>=k){
                    count=1;
                    while(!(nums[j++]&1))
                        count++;
                    total += count;
                }
            }
            else if(odd>=k)
                total += count;
        }
        
        return total;
    }
};