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
        ListNode* first = head;
        ListNode* second = head;
        ListNode* curr = head;
        int count = 1;
        while(curr){
            if(count<k) first = first->next;
            if(count>k) second = second->next;
            count++;
            curr = curr->next;
        }
        swap(first->val,second->val);
        return head;
    }
};