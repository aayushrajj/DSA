class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        
        int best = 0;
        while(low<=high){
            int capacity = low + (high-low)/2;
            int daysCount = 1;
            int loads = 0;
            for(int i=0;i<n;i++){
                loads += weights[i];
                if(loads>capacity){
                    daysCount++;
                    loads = weights[i];
                }
            }
            if(daysCount<=days){
                best = capacity;
                high = capacity-1;
            }
            else
                low = capacity+1;
        }
        
        return best;
    }
};