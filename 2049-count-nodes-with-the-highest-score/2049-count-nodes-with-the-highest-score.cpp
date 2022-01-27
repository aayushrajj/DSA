class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> size(n);
        vector<vector<int>> g(n);
        
        for(int i=1;i<n;i++){
            g[parents[i]].push_back(i);
        }
        
        helper(0,g,size);
        long long count = 0 , maxscore = 0;
        
        for(int i=0;i<n;i++){
            long long prod = 1;
            prod = max(prod , (long long)n-size[i]);
            for(auto subNode : g[i]){
                prod = prod * size[subNode];
            }
            if(prod>maxscore){
                maxscore = prod;
                count = 1;
            }
            else if(prod == maxscore)
                count++;
        }
        return count;
    }
    
    //helper function to to calculate size of subtrees
    int helper(int src,vector<vector<int>> &g,vector<int> &size){
        int ans = 1;
        for(auto child : g[src]){
            ans += helper(child,g,size);
        }
        return size[src] = ans;
    }
};