class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> store;
        for(auto v  : ops){
            if(v=="+"){
                int top = store.top();
                store.pop();
                int newtop = top + store.top();
                store.push(top);
                store.push(newtop);
            }
            else if(v=="C")
                store.pop();
            else if(v=="D"){
                int top = 2*store.top();
                store.push(top);
            }
            else{
                int val = stoi(v);
                store.push(val);
            }
        }
        int sum =0;
        while(!store.empty()){
            sum += store.top();
            store.pop();
        }
        return sum;
    }
};