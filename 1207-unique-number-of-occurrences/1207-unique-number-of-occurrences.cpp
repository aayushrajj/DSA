class Solution {
public:
    bool uniqueOccurrences(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq;
        set<int> count;
        
        for(int i : nums)
            freq[i]++;
        
        for(auto v : freq){
            int curr = v.second;
            if(count.find(curr) != count.end())
                return false;
            count.insert(curr);
        }
        
        return true;
    }
};