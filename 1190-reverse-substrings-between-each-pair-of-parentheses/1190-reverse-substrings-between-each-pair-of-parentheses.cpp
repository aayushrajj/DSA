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

        // vector<int> open;
        // vector<int> close;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='(')
        //         open.push_back(i);
        //     if(s[i]==')')
        //         close.push_back(i);
        // }
        // if(open.size()==0 || close.size()==0)
        //     return s;
        // int i = open.size()-1;
        // int j = 0;
        // while(i >=0 && j < close.size()){
        //     reverse(s.begin()+open[i]+1 , s.begin()+close[j]);
        //     s[open[i]] = '*';
        //     s[close[j]] = '*';
        //     i--;
        //     j++;
        // }
        // s.erase(remove(s.begin(),s.end(),'*'),s.end());