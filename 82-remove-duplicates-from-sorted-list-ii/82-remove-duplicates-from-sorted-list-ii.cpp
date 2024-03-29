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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            if(curr->next && curr->val==curr->next->val){
                while(curr->next && curr->val==curr->next->val)
                    curr  =curr->next;
                if(prev==NULL){
                    head = curr->next;
                    curr = curr->next;
                }
                else{
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};