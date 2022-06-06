class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string,int> map;
        for(int i=0;i<list1.size();i++)
            map.insert({list1[i],i});
        
        int leastIdx=INT_MAX;
        for(int i=0;i<list2.size();i++){
            if( map.find(list2[i]) != map.end() && leastIdx > i + map[list2[i]]){
                leastIdx = i + map[list2[i]];
                res.clear();
                res.push_back(list2[i]);
            }
            else if( map.find(list2[i]) != map.end() && leastIdx == i + map[list2[i]] )
                res.push_back(list2[i]);
        }
        return res;
    }
};