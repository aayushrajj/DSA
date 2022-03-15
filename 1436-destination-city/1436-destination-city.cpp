class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string destination;
        unordered_set<string> start;
        for(int i=0;i<paths.size();i++){
            start.insert(paths[i][0]);
        }
        for(int i=0;i<paths.size();i++){
            if(start.find(paths[i][1])==start.end())
                destination = paths[i][1];
        }
        return destination;
    }
};