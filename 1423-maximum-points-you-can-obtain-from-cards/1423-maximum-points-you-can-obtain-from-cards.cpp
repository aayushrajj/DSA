class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> preSum(n);
        preSum[0] = cardPoints[0];
        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + cardPoints[i];
        }
        int total = preSum[n-1];
        int maxScore = 0;
        int i=0,j=n-k-1;
        if(j<0) return total;
        while(j<n){
            if(i==0){
                maxScore = max(maxScore,total-preSum[j]);
            }
            else{
                maxScore = max(maxScore,total-preSum[j]+preSum[i-1]);
            }  
            i++;
            j++;
        }
        
        return maxScore;
    }
};