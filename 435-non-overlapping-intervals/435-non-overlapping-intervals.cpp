bool mysort(vector<int> &a , vector<int> &b){
    return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 0;
        sort(intervals.begin(),intervals.end(),mysort);
        int count = 0 , overlap = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<overlap){
                count++;
            }
            else
                overlap = intervals[i][1];
        }
        return count;
    }
};