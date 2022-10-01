// x XOR y = z  ==>> (x XOR y) XOR x = z XOR x
// y = z XOR x

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> res;
        res.push_back(first);
        for(int i=0;i<n;i++){
            int y = first^encoded[i];
            res.push_back(y);
            first = y;
        }
        
        return res;
    }
};