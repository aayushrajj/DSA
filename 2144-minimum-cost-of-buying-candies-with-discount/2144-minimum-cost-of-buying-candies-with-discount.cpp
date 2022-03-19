class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int res=0;
        int i = 0;
        while(i<n){
            if(i==n-1)
                res += cost[i];
            else
                res += cost[i]+cost[i+1];
            i = i+3;
        }
        return res;
    }
};