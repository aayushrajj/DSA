class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n==1) return cost[0];
        sort(cost.begin(),cost.end());
        int res=0;
        int i = n-1;
        while(i>=0){
            if(i==0)
                res += cost[i];
            else
                res += cost[i]+cost[i-1];
            i = i-3;
        }
        return res;
    }
};