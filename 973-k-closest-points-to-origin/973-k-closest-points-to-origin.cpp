class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>,vector<vector<int>>> store;
        for(auto &p : points){
            int x = p[0] , y = p[1];
            store.push({x*x+y*y,x,y});
            if(store.size()>k)
                store.pop();
        }
        for(int i=0;i<k;i++){
            vector<int> temp = store.top();
            store.pop();
            res.push_back({temp[1],temp[2]});
        }
        return res;
    }
};