class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++){
            int curr = check(i);
            count += curr;
        }
        
        return count;
    }
    
    int check(int n){
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19 };
        int bits=0;
        while(n){
            bits += n&1;
            n >>= 1;
        }
        
        return primes.count(bits);
    }
};