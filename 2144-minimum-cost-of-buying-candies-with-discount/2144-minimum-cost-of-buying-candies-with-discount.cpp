class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end(),greater<int>());
        int res=0;
        for(int i=0;i<n;i=i+3){
            if(i==n-1)
                res += cost[i];
            else
                res += cost[i]+cost[i+1];
        }
        return res;
    }
};