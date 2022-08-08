class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int n = grades.size();
        int i=0;
        int sum = 0;
        while(sum<n){
            i++;
            sum = (i*(i+1))/2;
            if(sum==n) return i;
        }
        return i-1;
    }
};