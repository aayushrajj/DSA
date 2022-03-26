bool mysort(const vector<int> &a,const vector<int> &b){
    // profit after going to city a i.e. Bcost - Acost
    return (a[1]-a[0]) > (b[1]-b[0]);
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(),mysort);
        
        int price = 0;
        for(int i = 0; i < costs.size() / 2; i++){
            price += costs[i][0];
        }
        for(int i = costs.size() / 2; i < costs.size(); i++){
            price += costs[i][1];
        }
        return price;
    }
};