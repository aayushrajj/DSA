class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int low = 1;
        int high = *max_element(q.begin(),q.end());
        int ans = 0;
        while(low<high){
            int mid = low + (high-low)/2;
            
            if(can_distribute(q,n,mid))
                high = mid;
            else
                low = mid+1;
        }
        return high;
    }
    
    bool can_distribute(vector<int>& q,int n,int barrier){
        int count=0;
        for(int i=0;i<q.size();i++){
            if(q[i]<=barrier)
                count++;
            else{
                int temp = q[i];
                while(temp>0){
                    temp -= barrier;
                    count++;
                }
            }
            if(count>n)
                return false;
        }
        return true;
    }
};