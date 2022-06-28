class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        priority_queue<int> pq;
        for(auto &v : map){
            pq.push(v.second);
        }
        
        int count =0;
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            if(first==pq.top()){
                count++;
                if(first-1>0){
                    first--;
                    pq.push(first);
                }           
            }
        }
        
        return count;
    }
};