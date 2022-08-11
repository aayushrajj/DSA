class Solution {
public:
    bool isHappy(int n) {
        set<int> store;
        int val;
        while(1){
            val =0;
            while(n){
                int index = n%10;
                val += index*index;
                n = n/10;
            }
            if(val==1)
                return true;
            else if(store.find(val)!=store.end())
                return false;
            store.insert(val);
            n = val;
        }
        return true;
    }
};