class Solution {
public:
    int WHITE = 0; // unvisited
    int GREY = 1; // explore incomplete
    int BLACK = 2; // explored completed
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> graph(numCourses);
        vector<int> visited(numCourses,WHITE);
        
        for(int i=0;i<prerequisites.size();i++){
            // all courses store their parents
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(visited[i]==WHITE){
                //below means cycle is present
                if(!dfs(graph,visited,result,i)){
                    result.clear();
                    break;
                }
            }
        }
        return result;
    }
    
    bool dfs(vector<vector<int>>& graph , vector<int> &visited , vector<int> &result , int node){
        visited[node] = GREY;
        for(int j=0;j<graph[node].size();j++){
            if(visited[graph[node][j]]==GREY)
                return false;
            if(visited[graph[node][j]]==WHITE){
                if(!dfs(graph,visited,result,graph[node][j]))
                    return false;
            }
        }
        visited[node] = 2;
        result.push_back(node);
        return true;
    }
};