class Solution {
public:
    int countVowelStrings(int n) {
        int count = 0;
        backtrack(n,0,count);
        return count;
    }
    
    void backtrack(int n,int last,int &count){
        if(n==0){
            count++;
            return;
        }
        for(int i=0;i<5;i++){
            if(i>=last){
                backtrack(n-1,i,count);
            }
        }
    }
};