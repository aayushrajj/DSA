class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        set<string> st,words;
        for(string p : wordList){
            words.insert(p);
        }
        st.insert(beginWord);
        q.push(beginWord);
        int count=0;
        while(q.size()){
            int n = q.size();
            count++;
            for(int i=0;i<n;i++){
                string s = q.front();
                if(s==endWord)
                    return count;
                q.pop();
                string t;
                for(int i=0;i<s.size();i++){
                    t=s;
                    for(int j ='a';j<='z';j++){
                        t[i] = j;
                        if(words.count(t) && !st.count(t)){
                            q.push(t);
                            st.insert(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};