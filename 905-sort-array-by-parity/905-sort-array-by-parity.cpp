class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for(int num : nums){
            if(num&1)
                result.push_back(num);
            else
                result.insert(result.begin(),num);
        }
        return result;
    }
};