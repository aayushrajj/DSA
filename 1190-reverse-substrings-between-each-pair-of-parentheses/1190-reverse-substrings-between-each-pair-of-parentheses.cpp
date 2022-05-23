class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(i);
            else if(s[i]==')'){
                reverse(s.begin()+st.top()+1,s.begin()+i);
                s[st.top()] = '*';
                s[i] = '*';
                st.pop();
            }
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};