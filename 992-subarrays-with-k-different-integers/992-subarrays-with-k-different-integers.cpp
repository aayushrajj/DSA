class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0,nsub=0,res=0,maxi=0,count=0;
        unordered_map<int,int> map;
        while(i<n){
            map[nums[i]]++;
            if(map[nums[i]]==1)
                count++;
            
            if(count==k){
                maxi = i;
                while(maxi+1<n && map[nums[maxi+1]]>0)
                    maxi++;
                nsub = maxi-i+1;
            }
            
            while(count==k && j<n){
                res += nsub;
                map[nums[j]]--;
                if(map[nums[j]]==0)
                    count--;
                j++;
            }
            i++;
        }
        return res;
    }
};