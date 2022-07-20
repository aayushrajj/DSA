class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(begin(position),end(position));
        int low=0 , high=position[n-1]-position[0];
        int bestGap=0;
        while(low<=high){
            int gap = low + (high-low)/2;
            int count=1;
            int prev = position[0];
            for(int i=1;i<n;i++){
                if(position[i]-prev>=gap){
                    count++;
                    prev = position[i];
                    if(count==m)
                        break;
                }
            }
            
            if(count==m){
                bestGap = gap;
                low = gap+1;
            }else
                high = gap-1;
        }
        
        return bestGap;
    }
};