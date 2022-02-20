class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int left = -1 , right = -1;
        for(auto v : intervals){
            if(v[0]>left && v[1]>right){
                left = v[0];
                count++;
            }
            right = max(right,v[1]);
        }
        return count;
    }
};