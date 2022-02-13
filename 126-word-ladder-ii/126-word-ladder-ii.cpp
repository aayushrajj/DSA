class Solution {
public:
    vector<vector<string>> ans;
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string , unordered_set<string>> adj;
        unordered_set<string> dict(wordList.begin(),wordList.end());
        
        queue<string> q;
        unordered_map<string,int> visited;
        q.push(beginWord);
        visited[beginWord] = 0;
        while(q.size()){
            string curr = q.front();
            q.pop();
            string temp = curr;
            for(int i=0;i<curr.size();i++){
                temp = curr;
                for(char j='a';j<='z';j++){
                    if(temp[i]==j)
                        continue;
                    temp[i] = j;
                    if(dict.count(temp)){
                        if(visited.count(temp)==0){
                            visited[temp] = 1 + visited[curr];
                            q.push(temp);
                            adj[curr].insert(temp);
                        }
                        else if(visited[temp]==visited[curr]+1){
                            adj[curr].insert(temp);
                        }
                    }
                }
            }
        }
        
        vector<string> path;
        DFS(beginWord,endWord,adj,path);
        return ans;   
    }
    
    //DFS FUNCTION
    void DFS(string& beginWord,string& endWord,unordered_map<string,unordered_set<string>>& adj,vector<string>& path){
        path.push_back(beginWord);
        if(beginWord==endWord){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto x : adj[beginWord]){
            DFS(x,endWord,adj,path);
        }
        
        path.pop_back();
    }
    
};