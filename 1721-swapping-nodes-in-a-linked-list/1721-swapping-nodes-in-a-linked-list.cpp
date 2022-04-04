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
    int maxcount=INT_MIN;
    ListNode* st = NULL;
    ListNode* swapNodes(ListNode* head, int k) {
        int count=1;
        return swapping(head,k,count);
    }
    
    ListNode* swapping(ListNode* head,int k,int count){
        if(head==NULL)
            return NULL;
        maxcount = max(maxcount,count);
        swapping(head->next,k,count+1);
        if(count==k or maxcount-count==k-1){
            if(st==NULL)
                st = head;
            else
                swap(head->val,st->val);
        }
        return head;
    }
};