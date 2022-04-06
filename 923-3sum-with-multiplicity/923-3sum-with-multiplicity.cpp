class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans =0;
        int mod = 1e9 + 7;
        for(int i=0;i<n-2;i++){
            int lo = i+1 , hi = n-1;
            while(lo<hi){
                if(arr[i]+arr[lo]+arr[hi]==target){
                    int countlo=1 , counthi=1;
                    while(lo<hi && arr[lo]==arr[lo+1]){
                        countlo++; lo++;
                    }   
                    while(lo<hi && arr[hi]==arr[hi-1]){
                       counthi++; hi--; 
                    }     
                    if(lo==hi)
                        ans = (ans + countlo*(countlo-1)/2)%mod;
                    else
                        ans = (ans + countlo*counthi)%mod;
                    lo++; hi--;
                }
                else if(arr[i]+arr[lo]+arr[hi]>target)
                    hi--;
                else
                    lo++;
            }
        }
        return ans;
    }
};