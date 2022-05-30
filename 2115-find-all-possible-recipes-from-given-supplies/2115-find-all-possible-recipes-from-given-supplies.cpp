class Solution {

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> mp;
        for(auto i:supplies) mp[i] = 1;
        vector<string> ans;
        int n = recipes.size();
        vector<int> pos(n,0);
        int prev = n;
        
        // O(n^4)
        
        while(1){ // O(100 * 10^6) = O(10^8)                                    O(100 * 10^5) = O(10^7)
            bool f = 0;
            for(int i = 0; i < n; i++){
                if(!pos[i]) {
                    f = 1;
                }
            }
            if(!f) break;
            for(int i = 0; i < n; i++){ // O(100 * 10^4) = O(10^6)                      O(100 * 10^3) = O(10^5)
                if(pos[i]) continue;
                f = 1;
                
                // len , O(len)
                // O(1)
                for(auto &j:ingredients[i]){ // O(100 * 10 * 10) = O(10^4)               when using &reference new O(100 * 10) = O(10 ^ 3)
                    if(!mp[j]){         //O(10)
                        f = 0;
                        break;
                    }
                }
                if(f){
                    mp[recipes[i]] = 1;
                    ans.push_back(recipes[i]);
                    pos[i] = 1;
                }
            }
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(!pos[i]) cnt++;
            }
            if(cnt == prev) break;
            prev = cnt;
        }
        return ans;
    }
};