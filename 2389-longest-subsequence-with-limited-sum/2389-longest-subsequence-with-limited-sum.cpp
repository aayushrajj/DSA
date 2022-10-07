class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> res;
        
        sort(nums.begin(),nums.end());

        for(auto query : queries){
            int count =0;
            for(auto num : nums){
                if(query >= num){
                    query -= num;
                    count++;
                }
                else
                    break;
            }
            
            res.push_back(count);
        }
        
        return res;
    }
};