class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) 
            return -1;
        auto p = minmax_element(bloomDay.begin(),bloomDay.end());
        
        int low = *p.first;
        int high = *p.second;
        
        while(low<high){
            int mid = low + (high-low)/2;
            
            if(canHarvest(bloomDay,mid,m,k))
                high = mid;
            else
                low = mid+1;
        }
        
        return low;
    }
    
    bool canHarvest(vector<int> &bloomDay,int day,int m ,int k){
        int count =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day)
                count++;
            else
                count=0;
            if(count==k){
                m--;
                count=0;
            }
        }
        // are we making all bouquets possible with current harvest date?
        return m<=0; 
    }
};