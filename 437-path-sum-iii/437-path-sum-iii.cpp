/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count=0;
    long long target=0;
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,long long> map;
        map[0]++;
        target = targetSum;
        helper(root,map,0);
        
        return count;
    }
    
    void helper(TreeNode* root,unordered_map<long long,long long> &map,long long sum){
        if(root==NULL)
            return;
        sum += root->val;
        if(map.find(sum-target)!=map.end())
            count += map[sum-target];
        map[sum]++;
        
        helper(root->left,map,sum);
        helper(root->right,map,sum);
        
        map[sum]--;
    }
};

// class Solution {
// public:
//     int pathSum(TreeNode* root, int sum) {
//         unordered_map<long long,long long> m;
//         m[0]++;
        
//         int total = 0;
//         helper(root, 0, sum, total, m);
//         return total;
//     }
    
//     void helper(TreeNode *p, long long cur, long long sum, int &total, unordered_map<long long,long long> &m) {
//         if (!p) return;
        
//         cur += p->val;
//         if (m.find(cur - sum) != m.end()) total += m[cur - sum];
//         m[cur]++;
        
//         helper(p->left, cur, sum, total, m);
//         helper(p->right, cur, sum, total, m);
        
//         m[cur]--;
//     }
// };