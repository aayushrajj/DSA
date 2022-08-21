class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freqMap , possibleMap;
        for (int i: nums) {
            freqMap[i]++;
        }
        
        for(int num  : nums){
            if(freqMap[num]==0)
                continue;
            
            if(possibleMap[num]>0){
                possibleMap[num]--;
                possibleMap[num+1]++;
                freqMap[num]--;
            }
            else if(freqMap[num]>0 && freqMap[num+1]>0 && freqMap[num+2]>0){
                freqMap[num]--;
                freqMap[num+1]--;
                freqMap[num+2]--;
                possibleMap[num+3]++;
            }
            else
                return false;
        }
        
        return true;    
    }
};