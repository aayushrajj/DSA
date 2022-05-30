class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> adj;
        unordered_map<string,int> indegree;
        
        for(int i=0;i<ingredients.size();i++){
            for(int j=0;j<ingredients[i].size();j++){
                adj[ingredients[i][j]].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        vector<string> res;
        queue<string> q;
        for(int i=0;i<supplies.size();i++){
            q.push(supplies[i]);
        }
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            for(auto i : adj[top]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    res.push_back(i);
                }
            }
        }
        return res;
    }
};