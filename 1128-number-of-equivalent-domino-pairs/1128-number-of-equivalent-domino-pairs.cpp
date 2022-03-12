class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int count = 0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            int first = min(dominoes[i][0],dominoes[i][1]);
            int second = max(dominoes[i][0],dominoes[i][1]);
            int sum = first*10+second;
            count += freq[sum]++;         
        }
        return count;
    }
};