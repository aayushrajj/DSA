class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int num : arr){
            total += num;
        }
        if(total%3!=0) return false;
        int check = total/3;
        int prefix = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            prefix += arr[i];
            if(prefix==check)
                count++,prefix=0;
        }
        return count>=3;
    }
};