class Solution {
public:
    int maxDepth(string s) {
        int res = 0;
        int depth = 0;
        for( auto i : s){
            if(i=='(')
                depth++;
            if(i==')')
                depth--;
            res = max(res,depth);
        }
        return res;
    }
};