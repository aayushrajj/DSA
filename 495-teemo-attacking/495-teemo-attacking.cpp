class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        int end = 0;
        for(auto t : timeSeries){
            total += duration;
            if(t < end){
                total =  total - (end-t);
            }
            end = t + duration;
        }
        return total;
    }
};