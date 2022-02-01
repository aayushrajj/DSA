class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int total = duration;
        for(int i=1;i<n;i++){
            total += min(duration,timeSeries[i]-timeSeries[i-1]);
        }
        return total;
    }
};