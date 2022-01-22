bool mysort(vector<int> &a , vector<int> &b){
        return a[1] < b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points){
        sort(points.begin(),points.end(),mysort);
        int arrow = 0 , count = 0;
        for(int i =0;i<points.size();i++){
            if(arrow==0 || points[i][0] > arrow){
                count++;
                arrow = points[i][1];
            }
        }
        return count;
    }
};