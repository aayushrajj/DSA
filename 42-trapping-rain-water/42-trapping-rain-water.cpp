class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        vector<int> maxL(n);
        vector<int> maxR(n);
        for(int i=0;i<n;i++){
            if(i==0)
                maxL[i] = height[i];
            else
                maxL[i] = max(maxL[i-1] , height[i]);
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)
                maxR[i] = height[i];
            else
                maxR[i] = max(maxR[i+1] , height[i]);
        }
        for(int i=0;i<n;i++){
            int lowerbuilding = min(maxL[i] , maxR[i]);
            int waterTrapped = lowerbuilding - height[i];
            total += waterTrapped;
        }
        return total;
    }
};