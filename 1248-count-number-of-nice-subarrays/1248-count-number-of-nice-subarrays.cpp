class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
//         int n = nums.size();
//         int i=0,j=0;
//         int total=0,ans=0,count=0;
        
//         while(j<n){
//             if(nums[j]&1){
//                 count++;
//                 if(count>=k){
//                     ans = 1;
//                     while(nums[i]%2==0){
//                         ans++;
//                         i++;
//                     }
//                     total += ans;
//                 }
//             }
//             else if(count>=k)
//                 total += ans;
//             j++;
//         }
//         return total;
        
        int n = nums.size();
        int i=0,j =0, total =0, count =0;
        int odd=0;
        while(i<n){
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
            i++;
        }
        
        return total;
    }
};