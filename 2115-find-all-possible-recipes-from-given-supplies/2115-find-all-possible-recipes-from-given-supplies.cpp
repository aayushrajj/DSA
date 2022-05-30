class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> map1;
        for(auto i : supplies)
            map1[i] = 1;
        int n = recipes.size();
        vector<int> created(n,0);
        vector<string> res;
        int prevPossible = n;
        while(1){
            bool flag= false;
            for(int i=0;i<n;i++){
                if(created[i]==0) // check if atleast one recipe is not prepared yet
                    flag = true;
            }
            if(!flag)
                break;
            for(int i=0;i<n;i++){
                // if curr recipe is already prepared than continue;
                if(created[i]==1)
                    continue;
                
                bool check = true;
                for(auto &j : ingredients[i]){
                    // if needed ingredient is not available currently
                    if( !map1.count(j) ){
                        check = false;
                        break;
                    }
                }
                if(check==true){
                    res.push_back(recipes[i]);
                    map1[recipes[i]] = 1;
                    created[i] = 1;
                }
            }
            int currPossible = 0;
            for(int i=0;i<n;i++){
                if(created[i]==1)
                    currPossible++;
            }
            if(prevPossible==currPossible)
                break;
            else
                prevPossible = currPossible;
        }
        return res;
    }
};