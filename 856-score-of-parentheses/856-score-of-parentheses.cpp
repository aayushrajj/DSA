class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        char prev = '(';
        stack<int> st;
        int depth = 0,res = 0;
        for(auto c : s){
            if(c=='(')
                depth++;
            else{
                depth--;
                if(prev=='(')
                    res += pow(2,depth);
            }
            prev = c;
        }
        return res;
    }
};