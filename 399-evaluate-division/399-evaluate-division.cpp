class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> adjList;
    unordered_map<string,bool> visited;
    double queryAns;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        vector<double> result(m);
        
        for(int i=0;i<n;i++){
            auto firstVar = equations[i][0];
            auto secVar = equations[i][1];
            adjList[firstVar].push_back( { secVar , values[i] } );
            adjList[secVar].push_back( { firstVar , 1/values[i] } );
        }
        
        for(int i=0;i<m;i++){
            queryAns = 1;
            bool pathFound = dfs( queries[i][0] , queries[i][1] , 1);
            if(pathFound)
                result[i] = queryAns;
            else
                result[i] = -1;
        }
        
        return result;
    }
    
    bool dfs(string startNode , string endNode , double runningProduct){
        if(startNode==endNode && adjList.find(startNode)!=adjList.end()){
            queryAns = runningProduct;
            return true;
        }
        
        bool tempAns = false;
        visited[startNode] = true;
        for(int i=0; i < adjList[startNode].size(); i++){
            auto denominator = adjList[startNode][i].first;
            auto prod = adjList[startNode][i].second;
            if(!visited[denominator]){
                tempAns = dfs(denominator , endNode , runningProduct*prod);
                if(tempAns)
                    break;
            }    
        }
        
        visited[startNode] = false;
        return tempAns;
    }
};