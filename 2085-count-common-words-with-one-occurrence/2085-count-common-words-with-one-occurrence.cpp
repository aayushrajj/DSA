class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> map1;
        unordered_map<string,int> map2;
        int count=0;
        for(auto v : words1)
            map1[v]++;
        for(auto v : words2)
            map2[v]++;
        for(auto v : map1){
            if(map1[v.first]==1 && map2[v.first]==1)
                count++;
        }
        return count;
    }
};