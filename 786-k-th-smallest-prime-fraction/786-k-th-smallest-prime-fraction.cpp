typedef pair<double,pair<int,int>> pr;
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pr, vector<pr>, greater<pr>> store;
        
        for(int i=0;i<n;i++){
            double a = (float)nums[i];
            for(int j=i+1;j<n;j++){
                double b = (float)nums[j];
                double c = a/b;
                store.push({c,{nums[i],nums[j]}});
            }
        }
        
        
        while(k>1){
            store.pop();
            k--;
        }
        
        return {store.top().second.first,store.top().second.second};
    }
};