class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map;
        for(auto num : nums){
            map.insert(num);
        }
        
        int maxlen=0;
        for(auto num : nums){
            if(map.find(num-1)==map.end()){
                int current = num;
                int currlen=1;
                
                while(map.find(current+1)!=map.end()){
                    current += 1;
                    currlen++;
                }
                
                maxlen = max(maxlen,currlen);
            }
        }
        
        return maxlen;
    }
};