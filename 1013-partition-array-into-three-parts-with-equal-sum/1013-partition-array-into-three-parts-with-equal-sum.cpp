class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int num : arr){
            total += num;
        }
        if(total%3!=0) return false;
        int prefix = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            prefix += arr[i];
            if(prefix==total/3)
                count++,prefix=0;
        }
        return count>=3;
    }
};