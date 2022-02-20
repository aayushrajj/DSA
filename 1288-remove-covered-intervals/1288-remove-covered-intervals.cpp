bool mysort(vector<int> &a , vector<int> &b){
    return a[1]<b[1];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),mysort);
        vector<bool> map(n,false);
        int count=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(map[j]==false && intervals[i][0]<=intervals[j][0]){
                    count++;
                    map[j]=true;
                }
                else if(map[j]==false && intervals[i][1]==intervals[j][1]){
                    if(intervals[i][0]>intervals[j][0]){
                        count++;
                        map[i]=true;
                    }
                }
            }
        }
        return n-count;
    }
};