class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int open = 0;
        int close = 0;
        stack<int> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
                st.push(s[i]);
            else{
                if(i<n && s[i+1]==')'){
                    if(!st.empty())
                        st.pop();
                    else
                        open++;
                    i++;
                }
                else{
                    if(st.empty()){
                        close++;
                        open++;
                    }
                    else{
                        close++;
                        st.pop();
                    }
                }      
            }
        }
        int total = st.size() * 2 + open + close;
        return total;
    }
};