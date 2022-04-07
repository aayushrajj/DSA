class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto stone : stones)
            pq.push(stone);
        while(!pq.empty()){
            if(pq.size()==1)
                return pq.top();
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(first!=second)
                pq.push(first-second);
        }
        return 0;
    }
};