class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int belowCount=0;
        int tCount = 0 ;
        for(auto num : nums){
            if(num<target)
                belowCount++;
            else if(num==target)
                tCount++;
        }
        
        vector<int> res;
        for(int i=0;i<tCount;i++){
            res.push_back(belowCount);
            belowCount++;
        }
        
        return res;
    }
};