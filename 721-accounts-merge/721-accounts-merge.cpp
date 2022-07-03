class UnionFind{
private:
    vector<int> parent;
    vector<int> ranks;
public:
    int groupCount;
    UnionFind(int n){
        groupCount = n;
        parent.resize(n);
        ranks.resize(n);
    }
    void intialize(int x){
        parent[x] = x;
    }
    int find(int x){
        if(x!=parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unify(int x,int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX==rootY) return;
        groupCount--;
        if(ranks[rootX]>ranks[rootY])
            parent[rootY] = rootX;
        else{
            parent[rootX] = rootY;
            if(ranks[rootX]==ranks[rootY])
                ranks[rootY]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);
        
        unordered_map<string,int> mail2accountIdx;
        for(int i=0;i<n;i++){
            uf.intialize(i);
            auto &curr = accounts[i];
            for(int j=1;j<curr.size();j++){
                auto &email = curr[j];
                auto it = mail2accountIdx.find(email);
                if(it==mail2accountIdx.end())
                    mail2accountIdx[email] = i;
                else{
                    uf.unify(i,it->second);
                }
            }
        }
        
        int mergedAccountsCount = uf.groupCount;
        vector<vector<string>> mergedAccounts(mergedAccountsCount);
        unordered_map<int,int> groupIdx2Idx;
        int nextIdx =0;
        
        for(auto &pair : mail2accountIdx){
            auto email = pair.first;
            auto groupId = uf.find(pair.second);
            auto it = groupIdx2Idx.find(groupId);
            if(it==groupIdx2Idx.end()){
                groupIdx2Idx[groupId] = nextIdx;
                auto owner = accounts[groupId][0];
                mergedAccounts[nextIdx].push_back(owner);
                mergedAccounts[nextIdx].push_back(email);
                nextIdx++;
            }
            else{
                mergedAccounts[it->second].push_back(email);
            }
        }
        
        for(int i=0;i<mergedAccountsCount;i++){
            auto &emails = mergedAccounts[i];
            sort(emails.begin()+1,emails.end());
        }
        
        return mergedAccounts;
    }
};