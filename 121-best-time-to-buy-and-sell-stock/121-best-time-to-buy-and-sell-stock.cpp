class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;
        int start = 0;
        int end = 1;
        while(end<n){
            if(prices[end]>prices[start])
                maxprofit = max(maxprofit,prices[end]-prices[start]);
            else
                start = end;
            end++;
        }
        return maxprofit;
    }
};