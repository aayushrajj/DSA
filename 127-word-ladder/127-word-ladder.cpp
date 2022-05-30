class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        set<string> visited,words;
        for(auto word : wordList){
            words.insert(word);
        }
        q.push(beginWord);
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            count++;
            for(int i=0;i<n;i++){
                string top = q.front();
                if(top==endWord)
                    return count;
                q.pop();
                string t;
                for(int i=0;i<top.size();i++){
                    t = top;
                    for(int j='a';j<='z';j++){
                        t[i] = j;
                        if(words.count(t) && !visited.count(t)){
                            visited.insert(t);
                            q.push(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};