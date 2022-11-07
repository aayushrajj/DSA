class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(int v : nums){
            if(count==0){
                candidate = v;
            }
            count += (v==candidate) ? 1 : -1;
        }
        return candidate;
    }
};