class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double total = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            pq.push(nums[i]);
        }
        int op = 0;
        double sum = total/2;
        while(total>sum){
            double hi = pq.top();
            pq.pop();
            total -= hi;
            double half = hi/2;
            total += half;
            op++;
            if(sum>=total)
                break;
            pq.push(half);
        }
        
        return op;
    }
};