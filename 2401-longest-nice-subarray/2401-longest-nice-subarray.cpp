class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int bits[31] = {0};
        int l=0 , res=0;
        
        for(int i=0;i<nums.size();i++){
            bool flag = false;
            for(int k=0;k<31;k++){
                if(nums[i] & (1<<k)){
                    bits[k]++;
                    if(bits[k]>1)
                        flag = true;
                }
            }
            
            if(!flag)
                res = max(res,i-l+1);
            else{
                while(l<=i){
                    for(int k=0;k<31;k++){
                        if(nums[l] & (1<<k))
                            bits[k]--;
                    }
                    l++;
                    bool flag = false;
                    for(int k=0;k<31;k++){
                        if(bits[k]>1)
                            flag = true;
                    }
                    if(!flag) break;
                }
            }    
        }
        
        return res;
    }
};