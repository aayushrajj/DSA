class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<pair<int,int>,int> freq;
        for(auto v : dominoes){
            if(v[0]>v[1])
                swap(v[0],v[1]);
            count += freq[make_pair(v[0],v[1])]++;         
        }
        return count;
    }
};