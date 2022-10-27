class Solution {
public:
    int minOperations(int n) {
        int sum = n*n;
        int target = sum/n;
        int i=1,steps=0;
        while(i<target){
            steps += target-i;
            i+=2;
        }
        return steps;
    }
};