/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* ans = head;
        vector<int> vec;
        while(temp){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        swap(vec[k-1],vec[vec.size()-k]);
        int j=0;
        while(ans){
            ans->val = vec[j];
            ans = ans->next;
            j++;
        }
        return head;
    }
};