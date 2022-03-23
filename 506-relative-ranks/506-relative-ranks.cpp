class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> rank(n,"");
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push(make_pair(score[i],i));
        }
        for(int i=0;i<n;i++){
            auto curr = pq.top();
            if(i==0) rank[curr.second] = "Gold Medal";
            else if (i==1) rank[curr.second] = "Silver Medal";
            else if (i==2) rank[curr.second] = "Bronze Medal";
            else rank[curr.second] = to_string(i+1);
            pq.pop();
        }
        return rank;
    }
};